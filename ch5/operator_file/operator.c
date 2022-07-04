/* 연산자 */

#include <stdio.h>

int main()
{
    /* 나누기 연산자 */
    
    /* integer division */
    // 값이 부동소수점이라도 형식 지정자가 정수형이기 때문에 나머지를 버린다.
    /*
    printf("%d\n", 14 / 7);     // 2
    printf("%d\n", 7 / 2);      // 3, 3.5 in floating division
    printf("%d\n", 7 / 3);      // 2, 2.333 in floating division
    printf("%d\n", 7 / 4);      // 1, 1.75 in floating division
    printf("%d\n", 8 / 4);      // 2
    */
    /* truncating toward zero (c99) */
    // 나머지는 버린다.
    /*
    printf("%d\n", -7 / 2);     // -3
    printf("%d\n", -7 / 3);     // -2
    printf("%d\n", -7 / 4);     // -1
    printf("%d\n", -8 / 4);     // -2
    */
    /* floating division */
    /*
    printf("%f\n", 9.0 / 4.0);      // 2.250000
    printf("%f\n", 9.0 / 4);        // 2.250000, 자료형이 다른 두 숫자끼리 곱셈, 나눗셈을 할 수 없다. 
                                    // compiler가 내부적으로 integer 4를 double로 바꾸어 진행
    return 0;
    */
    
    /* 나머지 연산자 */
    /*
    int seconds = 0, minutes = 0, hours = 0;

    printf("Input seconds : ");
    scanf("%d", &seconds);

    while (seconds >= 0)
    {
        minutes = seconds / 60;
        seconds = seconds % 60;
        // seconds %= 60; 같은 의미

        hours = minutes / 60;
        minutes = minutes % 60;

        printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

        printf("Input seconds : ");
        scanf("%d", &seconds);
    }

    printf("Good bye\n");

    return 0;
    */

    /* 음수 나누기 */
    
    // div : 나누기 결과 값, mod : 나머지 값
    // 나머지는 나누려는 값의 부호를 따라간다. 

    int div, mod;

    div = 11 / 5;
    mod = 11 % 5;
    printf("div = %d, mod = %d\n", div, mod);   // div = 2, mod = 1

    div = 11 / -5;
    mod = 11 % -5;
    printf("div = %d, mod = %d\n", div, mod);   // div = -2, mod = 1

    div = -11 / -5;
    mod = -11 % -5;
    printf("div = %d, mod = %d\n", div, mod);   // div = 2, mod = -1

    div = -11 / 5;
    mod = -11 % 5;
    printf("div = %d, mod = %d\n", div, mod);   // div = -2, mod = -1

    return 0;
}
