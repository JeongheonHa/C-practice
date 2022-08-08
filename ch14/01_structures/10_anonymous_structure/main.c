/* 익명 구조체 */
// 구조체 안에 구조체를 넣을 경우 tag가 없는 anonymous structure 형태로 넣을 수 있다.

#include <stdio.h>

struct names
{
    char first[20];
    char last[20];
};

struct person
{
    int id;
    struct names name;  // nested structure member
};

struct person2
{
    int id;
    struct { char first[20]; char last[20]; };  // anonymous structure (tag X, member만 있다)
};

int main()
{
    struct person ted = { 123, {"Bill", "Gates"} };
    struct person ted3 = { 125, "Robert", "Hand" };

    puts(ted.name.first);   // member access 2번
    puts(ted3.name.first);

    struct person2 ted2 = { 124, {"Steve", "wozniak"} };

    puts(ted2.first);   // tag없이 anonymous member로 직접 접근 가능 (member access 1번)

    return 0;
}