/* 텍스트 파일 모드 스트링과 다양한 입출력 함수들 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    /*
        fopen mode strings for text files (" ")
        - r : reading
        - w : creating-and-writing or over-writing (파일이 없다면 만들고 쓰고, 있을 경우 기존내용 모두 지우고 덮어쓰기)
        - a : appending or creating-and-writing (파일이 없다면 만들고 쓰고, 있을 경우 덧붙이기)
        - r+ : both reading and writing
        - w+ : reading and writing, over-writing or creating
        - a+ : reading and writing, appending or creating
    */

#define MAX 31

int main(void)
{
    FILE* fp;
    char words[MAX] = { '\0', };
    const char* filename = "record.txt";
    

    if((fp = fopen(filename, "r+")) == NULL)
    {
        fprintf(stderr, "Can't open \"%s\" file.\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))    // 빈칸을 만나면 읽는거 stop
        fprintf(fp, "%s\n", words);

    // while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))  // 문장 출력에 좋은 함수
    //      fputs(words, fp);

    rewind(fp); // go back to beginning of file

    while (fscanf(fp, "%s", words) == 1)
        fprintf(stdout, "%s\n", words);

    // while (fgets(words, MAX, fp) != NULL)
    //     fputs(words, stdout);

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}