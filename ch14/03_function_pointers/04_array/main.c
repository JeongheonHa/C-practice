/* array */
// 입력한 문자 대문자로 만들지 소문자로 만들지 선택 후 실행하는 파일 만들기

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main()
{
    char options[] = { 'u', '1' };
    int n = sizeof(options) / sizeof(char);

    typedef void (*FUNC_TYPE)(char*);
    FUNC_TYPE operations[] = { ToUpper, ToLower };

    printf("Enter a string\n>> ");

    char input[100];

    while (scanf("%[^\n]%*c", input) != 1)
        printf("Please try again.\n>> ");

    while(true)
    {
        printf("Choose an option:\n");
        printf("u) to upper\n");
        printf("i) to lower\n");

        char c;
        while (scanf("%c%*[^\n]%*c", &c) != 1)
            printf("Please try again.\n");

        bool found = false;

        // <1>
        // switch (c)
        // {
        // case 'u':
        //     ToUpper(input);
        //     found = true;
        //     break;
        // case '1':
        //     ToLower(input);
        //     found = true;
        //     break;
        // }

        // <2>  <1> 보다 더 유연한 코드이다. 
        // 원소를 추가할 경우 원소만 추가시키고 for문은 고칠 겻이 없기 때문에 유지 보수에 유연하다.
        for (int i = 0; i < n; ++i) 
            if (options[i] == c) {
                (*(operations[i]))(input);
                found = true;
                break;
            }
        if (found)
            break;
        else
            printf("Wrong input, try again\n");
    }

    printf("%s\n", input);

    return 0;
}

void update_string(char* str, int(*pf)(int))
{
    while (*str)
    {
        *str = (*pf)(*str);
        str++;
    }
}

void ToUpper(char* str)
{
    update_string(str, toupper);
}

void ToLower(char* str)
{
    update_string(str, tolower);
}

void Transpose(char* str)
{
    while (*str)
    {
        if (islower(*str))
            * str = toupper(*str);
        else if (isupper(*str))
            * str = tolower(*str);
        str++;
    }
}