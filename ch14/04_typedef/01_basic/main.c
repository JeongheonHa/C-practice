/* typedef */

#include <stdio.h>
#include <time.h>   // time()

int main()
{
    /*
        typedef specifier
        - give symbolic names (or aliases) to types
        - does not create new types (이름을 붙여주는 것 뿐 새로운 자료형을 만드는 것은 아니다.)
    */

    typedef unsigned char BYTE;

    BYTE x, y[10] = { 0, }, * z = &x;

    {
        typedef unsigned char byte;

        /* portable data types */

        size_t s = sizeof(byte);    // sizeof가 계산해서 주는 자료형은 unsigned int (x86), unsigned long long (x64)
                                    // size_t라는 자료형이 있는 것 처럼 x86, x64에 맞게 자유롭게 자료형이 변환된다.
    }

    // byte b;  // typedef definition has a scope (scope를 벗어난 typedef롤 만든 자료형은 사용할 수 없다)

    /*
        time() 
        - this function returns the time since 00:00:00 UTC, january 1, 1970 (Unix timestamp)
        - in second
    */

    time_t t = time(NULL);

    printf("%ld\n", t);

    /*
        typedef vs #define
    */

    typedef char* STRING;

    STRING name = "John Wick", sign = "World";

    /*
        <typedef> *권장*
        - 컴파일러에의해 수행된다.

        vs

        <#define>
        - 컴파일전에 처리되기 때문에 단순히 복사 붙여넣기를 할 뿐이다.

        // #define을 typedef처럼 사용했을 때의 문제점
        {
            #define STRING char *

            STRING name, sign;
            char * name, sign   // 정확한 표현 (char * name, * sign)
        }
    */

    /* complex */
    // 자료형이 추가되기 전에는 이런 형식을 만들어서 사용했다.

    typedef struct complex {
        float real;
        float imag;
    } COMPLEX;

    typedef struct { double width; double height; } rect;
    rect r1 = { 1.1, 2.2 };
    rect r2 = r1;
    printf("%f %f\n", r2.width,r2.height);

    return 0;
}