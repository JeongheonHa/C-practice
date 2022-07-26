/* 조건에 따라 다르게 컴파일하기 */

#include <stdio.h>

/*
    #define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/*
    #undef
*/
// 선언을 무효화 한다. (정의가 되어있지않은 매크로도 가능)

#define LIMIT 400
// #undef LIMIT

int main()
{
    printf("%d\n", LIMIT);

    return 0;
}