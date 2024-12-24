#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image_name");
        return 1;
    }
    char *filename = argv[1];
    FILE *file = fopen(filename,"r");
    if(file == NULL)
    {
        printf("error: unable to open the image");
        return 1;
    }
    int i = 0;
    BYTE buffer[512];
    FILE *out_file = NULL;
    char jpgfile[8];



    while (fread(buffer,1,512, file) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 0xef >= buffer[3] && buffer[3] >= 0xe0)
        {
            if(i < 10)
            {
                sprintf(jpgfile,"00%d.jpg",i);           //sprintf(jpg_filename, "%03i.jpg", jpg_count);
            }else{
                sprintf(jpgfile,"0%d.jpg",i);                         //(buffer[3] & 0xf0) == 0xe0
            }
            i++;
            if (out_file != NULL)
            fclose(out_file);
            out_file = fopen(jpgfile,"w");
            if(out_file == NULL)
            {
                fclose(file);
                printf("error: no enough memory");
                return 1;
            }


        }
        fwrite(buffer,1,512,out_file);
    }
    if(out_file != NULL)
    {
        fclose(out_file);
    }
    fclose(file);



//将错误信息输出到标准错误

//使用 fprintf 将错误信息输出到 stderr 而不是 stdout，更符合惯例，便于调试和日志记录。
//示例：
//c
//复制代码
//fprintf(stderr, "error: unable to open the image\n");


}
