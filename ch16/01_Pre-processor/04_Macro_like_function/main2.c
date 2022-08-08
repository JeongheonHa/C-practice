#include <stdio.h>

/*
    stringizing operator #
    - convert macro parameters to string literals
*/
// 매크로 인자에 #을 붙이면 #x를 문자열(string literal)로 바꾼상태에서 컴파일 진행 (전처리기에서 #x를 문자열로 바꿈)
#define SQUARE(X)     (X)*(X)
#define PRINT_SQR1(x) printf("The square of %d is %d.\n", x, SQUARE(x))
#define PRINT_SQR2(x) printf("The square of " #x " is %d.\n", SQUARE(x))

/*
    ## operator combines two tokens into a single token
*/

#define XNAME(n)    x ## n  // x는 macro argument가 아니다. (x : 프로그래머가 타이핑한 것처럼)
#define PRT_XN(n)   printf("x" #n " = %d\n", x ## n);

int main()
{
    PRINT_SQR1(10);
    PRINT_SQR2(10);

    printf("\n");

    int XNAME(1) = 1;   // int x1 = 1;
    int XNAME(2) = 2;   // int x2 = 2;

    PRT_XN(1);
    PRT_XN(2);

    return 0;
}

/*
    Macro vs Function

    - no space in the macro name
    - use parentheses
    - use capital letters for macro function names
*/
// function을 사용하는 것이 더 낫다. (컴파일러는 함수처럼 사용한 매크로에 어떤 문제가 있는지 알 수 없지만 function은 컴파일러가 진행하기 때문에 오류를 잡아낼 수 있다)
// 다만, 코딩하는 분량을 줄여주고, 반복되는 부분을 인식하기 쉽게 하는 목적에서는 자주 사용한다.

// <ex>
#define MAX(X,Y)    ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y)    ((X) < (Y) ? (X) : (Y))
#define ABS(X,Y)    ((X) < 0 ? -(X):(X))
