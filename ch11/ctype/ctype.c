#include <stdio.h>
#include <string.h>
#include <ctype.h>  // toupper() : 대문자로 교체, ispunct() : 기호인지 아닌지 판단

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main()
{
    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n');
    if (new_line)
        * new_line = '\0';

    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));
}

void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        /*if (islower(*str))
            * str = toupper(*str); */   // 이미 구현되어있음
        str++;  // 주소를 증가
    }
}

int PunctCount(const char* str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))  // 기호라면
            ct++;
        str++;
    }
    return ct;
}