#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count{
    char first[NLEN];
    char last[NLEN];
    int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
    struct name_count user_name;

    receive_input(&user_name);
    count_characters(&user_name);
    show_result(&user_name);

    return 0;
}

char* s_gets(char* st, int n)   // c의 전통적인 방법
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            * find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

void receive_input(struct name_count* ptr_nc)
{
    int flag;

    printf("Input your first name:\n>> ");

    // s_gets(ptr_nc->first, NLEN);
    flag = scanf("%[^\n]%*c", ptr_nc->first);   // [^\n] : 줄바꿈이 나올 때까지 받아라 %*c : c하나를 무시해라 (^ : cap operator)
                                                // 사용자가 입력한 문자열에서 줄바꿈 기호를 무시해라
    if (flag != 1)
        printf("Wrong input");

    printf("Input your last name:\n>> ");

    // sgets(ptr_nc->last, NLEN);
    flag = scanf("%[^\n]%*c", ptr_nc->last);
    if (flag != 1)
        printf("Wrong input");
}

void count_characters(struct name_count* ptr_nc)
{
    ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);
}

void show_result(const struct name_count* ptr_nc)
{
    printf("Hi, %s %s. Your name has %d characters.\n",
        ptr_nc->first, ptr_nc->last, ptr_nc->num);
}

// c언어에서는 구조체안에 함수를 넣을 수 없지만 c++에서는 구조체안에 함수를 넣을 수 있다.
// 따라서, 객체지향에서는 함수를 structure안에 넣어버린다.
// 객체 (object) : 구조체 내에 데이터를 넣어놓고 해당 데이터들로 할 수 있는 기능도 구조체 안에 넣어 놓은 것