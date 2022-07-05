/* for문 */
// 반복문에는 크게 indefinite loop 와 counting loop로 나뉜다.
// counting loop의 특징
// 1. counter initialization
// 2. counter check
// 3. counter change

#include <stdio.h>

int main()
{
    /* <ex1> */
    // 기존의 while문을 이용할 경우
    /*
    int i;

    i = 1;

    while (i <= 10)
    {
        printf("%d", i);
        i++;
    }
    */

    /* <ex2> */
    /*
    // while문을 for문으로 만들 경우
    int i;

    for (i = 1; i <= 10; i++)   // for (int i = 1; ...)로 int i;변수선언을 for문 내에서 할 수 있다.
    {
        printf("%d", i);    // 간단하게 나올경우 {} 생략 가능
    }
    // 과정 : int i로 변수 선언 -> i = 1로 초기화 -> i 와 10비교 후 {}안으로 진입 후 출력 -> i++로 i증가
    //       -> 증가된 i와 10비교 -> ... -> i와 10비교 후 조건에 맞지않을 경우 루프 탈출
    return 0;
    */

    /* for문의 유연함 */
    /*
        for(initialize; test; update)
            statement
    */
    /* <ex1> */
    /*
    for (int i = 10; i > 0; i--)
        printf("%d", i);

    for (int i = 0; i < 100; i = i + 8)
        printf("%d", i);
    
    for (char c = 'A'; c <= 'Z'; c++)
        printf("%c", c);

    for (int i = 0; i * i < 10; i++)
        printf("%d", i);

    for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)     // 같은 자료형의 경우 여러개를 initialize 할 수 있다.
        printf("%d", x);

    for (double d = 100.0; d < 300; d = d * 1.1)
        printf("%f\n", d);
    */

    /* <ex2> */
    // for문에 빈칸으로 놓을 경우
    int i, n;
    n = 2;
    for (i = 2; n < 10; )
    {
        n = n * i;
        printf("%d\n", n);
    }

    for ( ; ; )     // while 문과 같다.
        printf("Hello!");

    return 0;
}
