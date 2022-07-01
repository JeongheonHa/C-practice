/* 부동소수점 타입 알아보기 */
/*
#include <stdio.h>

int main()
{
    
    printf("%u\n", sizeof(float));
    printf("%u\n", sizeof(double));
    printf("%u\n", sizeof(long double));

    float f = 123.456f;
    double d = 123.456;

    int i = 3;
    float f2 = 3.0f;
    double d2 = 3.0;

    float f3 = 1.234e10f;   // e or E 사용
    
    float f4 = 0x1.1p1;     // 16진수, e대신 p를 사용한 것이다.
    double d4 = 1.0625e0;

    printf("%f %F %e %E\n", f, f, f, f);    // 123.456001 123.456001 1.234560e+02 1.234560E+02
    printf("%f %F %e %E\n", d, d, d, d);    // 123.456000 123.456000 1.234560e+02 1.234560E+02
    printf("%a %A\n", f4, f4);  // %a, %A : 16진수를 표현하기위한 형식 지정자, 0x1.1p+1 0X1.1P+1
    printf("%a %A\n", d4, d4);  // 0x1.1p+0 0X1.1P+0

    return 0;
    
}
*/

/* 부동소수점의 한계 */

#include <stdio.h>
#include <float.h>

int main()
{
    /* round off errors */

    /* < ex1 > */
    /*
    float a, b;
    a = 1.0E20f + 0.1f;      
    b = a - 1.0E20f;

    printf("%f\n", b);  // 0.000000
    // 숫자의 범위차이가 많이 나기때문에 발생하는 현상.

    return 0;
    */

    /* <ex2> */
    /*
    float a = 0.0f;

    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
      
    printf("%f\n", a);
    // a = a + 0.01f;을 100번을 곱할 경우 1.0이 나올거 같지만 
    // 0.999999로 출력된다.
    // 부동소수점의 friction부분에서 1/2, 1/4, 1/8 ... 의 조합으로 만들기때문에 발생.

    return 0;
    */

    /* overflow */
    /*
    float max = 3.4023423223e+37F;

    printf("%f\n", max);    // 34023422662174419622362336863084085248.000000

    max = max * 100.0f;

    printf("%f\n", max);    // inf (infinity)
    // float -> double -> long double을 이용해 메모리의 사이즈를 키울 수 있지만
    // long double 보다 큰 수의 경우 동일한 결과인 inf 출력

    return 0;
    */

    /* underflow */
    
    float f = 1.234234234e-45F;

    printf("%e\n", f);  // 1.401298e-45

    f = f / 2.0f;   // subnormal : 부동소수점형의 정밀도로는 더 이상 표현할 수 없는 작은 수의 경우
                    //             수가 모두 날아가 버리는 현상
    printf("%e\n", f);  // 0.000000e+00

    return 0;
    
}




