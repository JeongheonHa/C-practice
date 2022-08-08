/* 가변 인수 매크로 */
// ...

#include <stdio.h>
#include <math.h>

/*
    Variadic Macros accept a variable number of arguments
*/

#define PRINT(X, ...) printf("Message " #X ": " __VA_ARGS__)    // variable argument가 몇 개가 들어올지 모를 경우 사용
// ... : ellipses
// __VA_ARGS :  one of the predefined macros (이미 정의된 매크로로 전처리기가 이미 알고있는 변수)
// ...에 들어온 arguments을 __VA_ARGS__자리에 복사해 준다.

int main()
{
    double x = 48;
    double y;

    y = sqrt(x);
    PRINT(1, "x = %g\n", x);                // printf("Message " "1" ": " "x = %g\n", x) 
    PRINT(2, "x = %.2f, y = %.4f\n", x, y); // printf("Message " "2" ": " "x = %.2f, y = %.4f\n", x, y)

    return 0;
}