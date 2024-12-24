#include <stdio.h>
#include <string.h>

#define MAX_WORDS 8000
#define MAX_LENGTH 25

int main() {
    char *inputFile = "6.txt";  // 输入文件名
    char *outputFile = "7.txt"; // 输出文件名
    FILE *p = fopen(inputFile, "r");
    FILE *q = fopen(outputFile, "w");

    if (p == NULL || q == NULL) {
        perror("Error opening file");
        return 1;
    }

    char words[MAX_WORDS][MAX_LENGTH];
    int wordCount = 0;
    char line[MAX_LENGTH];

    // 读取行并存储不重复的单词
    while (fgets(line, sizeof(line), p)) {
        line[strcspn(line, "\n")] = 0; // 去掉换行符
        int isDuplicate = 0;

        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], line) == 0) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            strcpy(words[wordCount], line);
            wordCount++;
        }
    }

    // 写入不重复的单词到输出文件
    for (int i = 0; i < wordCount; i++) {
        fprintf(q, "%s\n", words[i]);
    }

    fclose(p);
    fclose(q);
    return 0;
}
