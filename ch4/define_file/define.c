/* 기호적 상수(symbolic constants) & define */

#include <stdio.h>
#define PI 3.141592f    // define 전처리기를 통해 PI를 기호적 상수로 정의 (관습적으로 대문자로 정의)
#define NAME "JEONGHEON"    // 문자열의 경우 ""를 붙인다.

int main()
{
    float const pi = 3.141492f;  // 변수앞에 const를 붙여서 기호적 상수를 만드는 것(#define보다 이방법을 권장)
    float radius, area, circum;

    printf("My name is %s\n", NAME);
    printf("Input radius\n");

    scanf("%f", &radius);

    area = PI * radius * radius;
    circum = 2.0 * PI * radius;

    printf("Area is %f\n", area);
    printf("Circum is %f\n", circum);

    return 0;
}