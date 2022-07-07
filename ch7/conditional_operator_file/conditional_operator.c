/* 조건 연산자(conditional operator) ? : */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    /* <ex1> */
    /*
    int temp;
    temp = true ? 1024 : 7; // ternary, true면 왼쪽 false면 오른쪽 대입
    printf("%d\n", temp);

    temp = false ? 1024 : 7;
    printf("%d\n, temp");
    */

    /* <ex2> */
    int number;
    scanf("%d", &number);

    bool const is_even = (number % 2 == 0) ? true : false;   // ?의 경우 우선 순위가 매우 낮기 때문에 조건에 ()를 해준다.
                                                             // 조건에 따른 변수값을 선언과 동시에 const하고싶을 때 자주 사용

    if (is_even)
        printf("Number is Even\n");
    else
        printf("Number is Odd\n");
    
    // is_even == 1 ? printf("Even\n") : printf("Odd\n");   // 가능은 하나 flag를 세우고 거기에 따른 기능을 사용하는 것이 일반적이다.

    return 0;
}