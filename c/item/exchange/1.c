#include <stdio.h>

/*
int main()
{
    char *o = "2.txt";
    char *i = "1.txt";
    FILE *p = fopen(o,"r");
    FILE *q = fopen(i,"w");
    if (p == NULL || q == NULL) {
        perror("Error opening file");
        return 1;
    }
    char m[25];
    char u[2] = "\r\n";

    for(;;)
    {
        int c = fscanf(p,"%s",m);
        if (c == EOF)
        {
            break;
        }
        fprintf(q,"%s",m);
        fprintf(q,"%s",u);
        do
        {
            fscanf(p,"%c",m);
        }
        while(*m != '\n');
    }
    fclose(p);
    fclose(q);
    


}
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char *o = "2.txt"; // 输入文件
    char *i = "1.txt"; // 输出文件
    FILE *p = fopen(o, "r");
    FILE *q = fopen(i, "a");

    if (p == NULL || q == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256]; // 用于存储每行内容
    char m[25];     // 用于存储第一个字符串

    while (fgets(line, sizeof(line), p) != NULL) {
        // 提取第一个字符串
        sscanf(line, "%s", m);
        fprintf(q, "%s\r\n", m); // 输出到文件，并添加换行符
    }

    fclose(p);
    fclose(q);
    return 0;
}

/*
#include <stdio.h>

int main()
{
    char *o = "2.txt";
    char *i = "1.txt";
    FILE *p = fopen(o, "r");
    FILE *q = fopen(i, "w");
    if (p == NULL || q == NULL) {
        perror("Error opening file");
        return 1;
    }
    char m[25];
    char u[2] = "\r\n";

    while (fscanf(p, "%s", m) == 1) { // 检查是否成功读取
        fprintf(q, "%s", m);
        fprintf(q, "%s", u);

        char temp; // 使用临时变量
        do {
            temp = fgetc(p); // 读取下一个字符
        } while (temp != '\n' && temp != EOF); // 跳过当前行的剩余部分
    }

    fclose(p);
    fclose(q);
}

*/





                                                                                                    /*
                                                                                                    #include <stdio.h>

                                                                                                    int main()
                                                                                                    {
                                                                                                        char *o = "4.txt";
                                                                                                        char *i = "1.txt";
                                                                                                        FILE *p = fopen(o,"r");
                                                                                                        FILE *q = fopen(i,"w");
                                                                                                        if (p == NULL || q == NULL) {
                                                                                                            perror("Error opening file");
                                                                                                            return 1;
                                                                                                        }
                                                                                                        char m[25];
                                                                                                        for(;;)
                                                                                                        {
                                                                                                            int c = fscanf(p,"%s",m);
                                                                                                            if (c == EOF)
                                                                                                            {
                                                                                                                break;
                                                                                                            }
                                                                                                            fprintf(q,"%s\n",m);
                                                                                                        }
                                                                                                        fclose(p);
                                                                                                        fclose(q);
                                                                                                    }




                                                                                                    */





                                                                                                   /*
                                                                                                   
                                                                                                   #include <stdio.h>
                                                                                #include <stdlib.h>
                                                                                #include <string.h>
                                                                                #include <time.h>

                                                                                #define MAX_LINE_LENGTH 25
                                                                                #define MAX_WORDS 10000 // 假设最多有100个单词

                                                                                int main() {
                                                                                    FILE *inputFile, *outputFile;
                                                                                    char words[MAX_WORDS][MAX_LINE_LENGTH];
                                                                                    int wordCount = 0;
                                                                                    char line[MAX_LINE_LENGTH];

                                                                                    inputFile = fopen("1.txt", "r"); // 替换为你的输入文件名
                                                                                    if (inputFile == NULL) {
                                                                                        perror("Error opening input file");
                                                                                        return 1;
                                                                                    }

                                                                                    // 读取单词
                                                                                    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL && wordCount < MAX_WORDS) {
                                                                                        line[strcspn(line, "\r\n")] = 0; // 移除换行符
                                                                                        strcpy(words[wordCount], line);
                                                                                        wordCount++;
                                                                                    }
                                                                                    fclose(inputFile);

                                                                                    if (wordCount == 0) {
                                                                                        printf("No words found.\n");
                                                                                        return 1;
                                                                                    }

                                                                                    // 乱序单词
                                                                                    srand((unsigned int)time(NULL)); // 设置随机种子
                                                                                    for (int i = 0; i < wordCount; i++) {
                                                                                        int randomIndex = rand() % wordCount;
                                                                                        // 交换单词
                                                                                        char temp[MAX_LINE_LENGTH];
                                                                                        strcpy(temp, words[i]);
                                                                                        strcpy(words[i], words[randomIndex]);
                                                                                        strcpy(words[randomIndex], temp);
                                                                                    }

                                                                                    // 写入乱序后的单词到输出文件
                                                                                    outputFile = fopen("5.txt", "w"); // 替换为你的输出文件名
                                                                                    if (outputFile == NULL) {
                                                                                        perror("Error opening output file");
                                                                                        return 1;
                                                                                    }

                                                                                    for (int i = 0; i < wordCount; i++) {
                                                                                        fprintf(outputFile, "%s\n", words[i]);
                                                                                    }

                                                                                    fclose(outputFile);
                                                                                    return 0;
                                                                                }

                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                                                                                                
                                                                                                   */






                                                                                                  /*
                                                                                                  
                                                                                                  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void removeNumber(char *str) {
    int i = strlen(str) - 1;
    while (i >= 0 && isdigit(str[i])) {
        str[i] = '\0';
        i--;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];

    inputFile = fopen("5.txt", "r"); // 替换为你的输入文件名
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    outputFile = fopen("6.txt", "w"); // 替换为你的输出文件名
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        // 删除行首和行尾的空白字符
        line[strcspn(line, "\r\n")] = 0;
        // 删除单词后面的数字
        removeNumber(line);
        // 写入处理后的单词到输出文件
        fputs(line, outputFile);
        fputc('\n', outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
                                                                                                  
                                                                                                  */