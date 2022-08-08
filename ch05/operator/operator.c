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
    /*
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
    */

    /* ++/-- (증가/감소) 연산자 */
    // 변수의 앞,뒤에 붙을 수 있다.

    /* int에서 증감 */
    /*
    int a = 0;
    a++;    // postfix(후위 연산자), a = a + 1 or a += 1;
    printf("%d\n", a);

    ++a;    // freefix(전위 연산자), a = a + 1 or a += 1;
    printf("%d\n", a);
    */

    /* double에서 증감 */
    /*
    double b = 0;  
    b++;    // double에서도 같은 작용
    printf("%f\n", b);

    ++b;
    printf("%f\n", b);
    */

    /* while에서 증감 */
    /*
    int count = 0;
    while (count < 10)    // ++count : 123456789
                          // count++ : 12345678910, 현재상태에서 10과 비교를 먼저한 다음 비교가 끝나고 {}에 들어갈 때 숫자가 증가.
    {
        printf("%d", count++);    // ++count : 12345678910,
                                  // count++ : 0123456789, 0을 출력 후 자신의 숫자가 증가.
        
        // ++count;    // ++count or count++
    }

    printf("\n");
    */

    /* ++ 연산자 */
    /*
    int i = 1, j = 1;
    int i_post, pre_j;

    i_post = i++;
    pre_j = ++j;

    printf("%d %d\n", i, j);    // 2 2, i_post와 pre_j를 거치면서 증가한 상태의 i, j가됨.
    printf("%d %d\n", i_post, pre_j);   // 1 2, i++의 경우 i인 상태에서 i_post에 대입이 되고 그 후에 ++
    */

    /* -- 연산자 */
    /*
    int i = 3;
    int l = 2 * --i;    // 증감 연산자는 * /연산자보다 우선순위가 높다. ( ()괄호보다는 아니다. )
    printf("%d %d\n", i, l);    // 2 4

    i = 1;
    l = 2 * i--;    // i--와 같은 후위 연산자의 경우 * 먼저 연산 후 l에 대입까지 하고나서 -- 하기때문에 *가 먼저다.
    printf("%d %d\n", i, l);    // 0 2
    */

    /* 우선순위 */
    /*
    int x, y, z;
    x = 3, y = 4;
    z = (x + y++) * 5;

    printf("%d %d %d\n", x, y, z);  // 3 5 35
    */

    /* 증감 연산자 & 수정가능한 lvalue */
    /*
    // 증감 연산자는 수정가능한 lvalue에만 사용 가능.
    // literal이나 const에는 사용 X

    int x = 1, y = 1, z;

    z = x * y++;    
    // z = (x * y)++;   // rvalue이기 때문에 증감 연산자 사용 X
    // z = 5++;     // literal이기 때문에 증감 연산자 사용 X 
    */

    /* bad practices */
    // 증감 연산자는 명확할 때 사용한다.
    
    int n = 1;

    printf("%d %d\n", n, n * n++);  // 함수 호출시 n이 여러번 들어가 있는 경우에는 시스템마다 
                                    // 결과값이 다르게 출력될 수 있기 때문에증감 연산자를 사용하지 않는 것이 좋다.
    
    int x = n / 2 + 5 * (1 + n++);  // n이 여러번 들어가 있어 식을 쪼개어 증감 연산자를 사용하는 것이 좋다.
    
    int y = n++ + n++;      // 증감 연산자를 여러번 사용하는 것은 좋지 않다.

    return 0;
}
