/* 에제 비교해보기 */

#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
    char first[NLEN];
    char last[NLEN];
    int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);

int main()
{
    struct name_count user_name;

    user_name = receive_input();    // 스타일 차이
    user_name = count_characters(user_name);
    show_result(user_name);

    return 0;
}

struct name_count receive_input()
{
    struct name_count nc;

    int flag;

    printf("Input your first name:\n>>");

    flag = scanf("%[^\n]%*c", nc.first);
    if (flag != 1)
        printf("Wrong input");

    printf("Input your last name:\n>>");

    flag = scanf("%[^\n]%*c", nc.last);
    if (flag != 1)
        printf("Wrong input");

    return nc;
}

struct name_count count_characters(struct name_count nc)
{
    nc.num = strlen(nc.first) + strlen(nc.last);

    return nc;
}

void show_result(const struct name_count nc)
{
    printf("Hi, %s %s. Your name contains %d cahracters.\n",
        nc.first, nc.last, nc.num);
}