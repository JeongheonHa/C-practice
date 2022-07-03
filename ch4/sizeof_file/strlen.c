
/* 문자열 길이 */
// 문자열의 글자 수를 세준다.(null은 뺀다)
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100] = "Hello";
    char str2[] = "Hello";  // 문자열만큼 메모리 사이즈 확보
    char str3[100] = "\0";
    char str4[100] = "\n";

    printf("%zu %zu\n", sizeof(str1), strlen(str1));    // 100 5
    printf("%zu %zu\n", sizeof(str2), strlen(str2));    // 6 5
    printf("%zu %zu\n", sizeof(str3), strlen(str3));    // 100 0
    printf("%zu %zu\n", sizeof(str4), strlen(str4));    // 100 1

    return 0;
}