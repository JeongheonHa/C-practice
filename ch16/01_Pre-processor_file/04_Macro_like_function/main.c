/* 함수 같은 매크로 */

#include <stdio.h>

/*
    Function-like macros

    #define        ADD(X,Y)        ((X)+(Y))

    X and Y : macro arguments
*/

#define ADD1(X,Y)     X+Y        // 매크로 인자를 그대로 넣어주기 때문에 오류가 발생할 경우가 생김
#define ADD2(X,Y)    ((X)+(Y))   // 괄호를 사용하는 것을 *권장*
#define SQUARE(X)    X*X         // ((X)*(X)) 로 사용

int main()
{
    int sqr = SQUARE(3);

    int a = 1;

    printf("%d\n", 2 * ADD1(1, 3)); // 2 * X + Y = 2 * 1 + 3 = 5 (wrong)
    printf("%d\n", 2 * ADD2(1 ,3)); // 2 * (1 + 3) = 8

    printf("%d\n", SQUARE(1 + 2));  // 1 + 2 * 1 + 2 = 1 + 2 + 2 = 5 (wrong)
    printf("%d\n", 100 / SQUARE(3 + 1));    // wrong
    printf("%d\n", SQUARE(++a));    // ++a * ++a = 3 * 3 = 9 (dangerous)

    return 0;
}