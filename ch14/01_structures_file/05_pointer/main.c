/* 구조체와 포인터 */

#include <stdio.h>
#define LEN 20

struct names {
    char given[LEN];
    char family[LEN];
};

struct friend {
    struct names full_name;
    char mobile[LEN];
};

int main()
{
    struct friend my_friends[2] = {
        { { "Ariana", "Grande"}, "1234-1234" },
        { { "Taylor", "Swift"}, "6550-8888" }
    };

    struct friend* girl_friend;

    girl_friend = &my_friends[0];

    printf("%zd\n", sizeof(struct friend)); // 60
    printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);      // 6125761600 Ariana

    girl_friend++;

    printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);    // 6125761660 Taylor

    return 0;
}