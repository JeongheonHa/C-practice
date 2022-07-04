/* 자료형 변환 */

#include <stdio.h>

int main()
{
    /* promotions in assignments */
    // short -> int 로 대입
    short s = 64;
    int i = s;

    // float -> double 로 대입
    float f = 3.14f;
    double d = f;

    /* demotion in assignments */
    // demotion : 데이터가 큰 자료형을 데이터가 작은 자료형에 넣으려는 것

    d = 1.25;   // 1.25 : double의 literal
    f = 1.25;   // float형의 literal은 1.25f가 되어야하지만 1.25이므로 double형의 데이터를 float형에 demotion
    f = 1.123;
    
    /* ranking of types in operations */
    // long double > double > float
    // unsigned = signed
    // _Bool

    d = f + 1.234;
    f = f + 1.234;  // f + 1.234는 double이기때문에 f에 대입하려면 error발생

    /* casting operators */
    // "형 변환을 할거다"라는 것을 표현
    d = (double)3.14f;  // 3.14f이라는 expression은 형 변환되어 double이 된다.
    i = 1.6 + 1.7;      // 3
    i = (int)1.6 + (int)1.7;    // 2, 소수점 절삭

    /* more examples */
    char c;
    // int i;
    //float f;
    f = i = c = 'A';    // 65, demotion
    printf("%c %d %f\n", c, i, f);  // A 65 65.000000
    c = c + 2;  // 'C', 67
    i = f + 2 * c;  // 65.0f + 2 * 67, double로 형 변환 후 i에 대입되므로 소수점 절삭
    printf("%c %d %f\n", c, i, f);  // C 199 65.000000
    c = 1106;   // c는 1byte의 공간을 가지기 때문에 1106이 강등된 상태로 대입
                // 과정 : 1106 = (2진수)0b10001010010 ->(절삭) 0b01010010 = 82 = 'R' = (나머지 값)1106 % 256
    printf("%c\n", c);  // R (82)
    c = 83.99;
    printf("%c\n", c);  // S (83)
    
    return 0;
}