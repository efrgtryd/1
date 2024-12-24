#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // 检查命令行参数
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image_name\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        fprintf(stderr, "error: unable to open the image\n");
        return 1;
    }

    int jpg_count = 0;              // JPEG文件计数器
    BYTE buffer[512];
    FILE *out_file = NULL;          // 当前打开的JPEG文件指针
    char jpgfile[8];                // 足够存储 "000.jpg" 到 "999.jpg"

    // 读取每个512字节的块
    while (fread(buffer, 1, 512, file) == 512)
    {
        // 检查是否为JPEG头
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0)
        {
            // 如果已经有打开的文件，先关闭它
            if(out_file != NULL)
            {
                fclose(out_file);
            }

            // 生成新的文件名，例如 "000.jpg", "001.jpg", ..., "999.jpg"
            sprintf(jpgfile, "%03i.jpg", jpg_count);
            jpg_count++;

            // 打开新的JPEG文件
            out_file = fopen(jpgfile, "w");
            if(out_file == NULL)
            {
                fprintf(stderr, "error: no enough memory to create %s\n", jpgfile);
                fclose(file);
                return 1;
            }
        }

        // 如果有打开的JPEG文件，写入数据
        if(out_file != NULL)
        {
            size_t bytes_written = fwrite(buffer, 1, 512, out_file);
            if(bytes_written != 512)
            {
                fprintf(stderr, "error: failed to write to %s\n", jpgfile);
                fclose(file);
                fclose(out_file);
                return 1;
            }
        }
    }

    // 检查读取错误
    if(ferror(file))
    {
        fprintf(stderr, "error: reading the file\n");
        if(out_file != NULL)
            fclose(out_file);
        fclose(file);
        return 1;
    }

    // 关闭所有打开的文件
    if(out_file != NULL)
    {
        fclose(out_file);
    }
    fclose(file);

    return 0;
}
