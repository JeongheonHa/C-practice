/* 복소수형 */
// float _complex, double _complex, ldouble _complex 3가지 존재

#include <stdio.h>
#include <complex.h>

int main()
{
    double _Complex z = 1 + 2*I;    // I : 허수

    z = 1 / z;

    printf("1 / (1.0 + 2.0i) = %0.1f %+0.1fi\n", creal(z), cimag(z));
    // creal() : 실수 부분 가져오기, 형식 지정자 : %0.1f
    // cimag(z) : 허수 부분 가져오기, 형식 지정자 : +0.1fi

    return 0;
}