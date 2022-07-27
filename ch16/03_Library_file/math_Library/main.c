/* 표준 수학 라이브러리 */

#include <stdio.h>
#include <math.h>
#include <tgmath.h>

#define AQRT(X) _Generic((X), \
    long double : sqrt1, \
    float : sqrtf, \
    default : sqrt)(X)

int main()
{
    // <1> 
    // sqrt  : double을 받고 double로 반환
    // sqrtf : float로 받고 float로 반환

    printf("%f\n", cos(3.141592));

    double c = 5.0, b = 4.0, a;
    a = sqrt(c * c - b * b);
    printf("a = %f\n", a);

    float cf = 5.0f, bf = 4.0f, af;
    af = sqrtf(cf * cf - bf * bf);
    printf("af = %f\n", af);

    /*
        Type Variants
    */

    double t1 = SQRT(2.0f); // sqrtf를 사용하여 float값을 반환하고 자동으로 double로 캐스팅 되어 대입
    double t2 = SQRT(2.0);  // sqrt를 사용하여 double 반환

    if (t1 == t2)
        printf("Identical\n");

    /*
        tgmath.h Library
    */
    // 둘다 double을 입력받고 double을 
    double a1 = sqrt(2.0f); // tgmath를 include할 경우 
    double a2 = sqrt(2.0);

    if (a1 == a2)
        printf("Identical\n");
    else
        printf("Not identical\n");

    return 0;
}