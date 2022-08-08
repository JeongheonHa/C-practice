/* _Generic 표현식 */

#include <stdio.h>

/*
    Generic selction expression
    - Generic programming : code is not specific to a particular type (여러 자료형들에 대해서 모두 작동 가능한 코드를 만드는 것)

    _Generic : C11 keyword
*/

// X자리에는 expression이 들어갈 수 있다.
// expression의 자료형에 따라 반환하는 자료형이 달라진다.

#define MYTYPE(X) _Generic((X), \
    int : (X + 777), \
    float : "float", \
    double : "double", \
    long : "long", \
    int* : "int*", \
    default : "other"\
    )

    int main()
    {
        int d = 5;

        printf("%d\n", MYTYPE(d));      // 782, expression을 넣어줄 수 도 있다.
        printf("%s\n", MYTYPE(2.0*d));  // double
        printf("%s\n", MYTYPE(3L));     // long
        printf("%s\n", MYTYPE(&d));     // int*

        return 0;
    }