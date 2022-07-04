/* expression & statements */

#include <stdio.h>

int main()
{
    /* statement */
    /*
    int x, y, apples;   // declaration statement
    apples = 3;     // assignment statement
    ;   // null statement
    x = 1 + (y = 5);    // y = 5 is subexpression
    while (x++ < 10)    // while statement (structured statements)
    y = x + y;
    printf("%d\n", y);  // function statement
    return 0;   // return statement
    */

    /* side effects & sequence points */
    /*
    x = 4;
    y = 1 + x++;    // 주요 의도는 계산하는 것이다.

    while (x++ < 10)    // (x++ < 10) 은 완전한 문장이다.
    {
        printf("%d\n", x);
    }
        
    y = (4 + x++) + (6 + x++);  // sequnence point가 모호해서 시스템마다 게산값이 달라질 수 있다.
    */
}