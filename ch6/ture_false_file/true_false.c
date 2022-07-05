/* true & false */
// true가 1이라고 정의하는 것이 아니라
// 0이면 false이고 0이외는 다 true

#include <stdio.h>

int main()
{
    /* <ex1> */
    /*
    int tv, fv;
    tv = (1 < 2);
    fv = (1 > 2);

    printf("True is %d\n", tv);     // True is 1
    printf("False is %d\n", fv);    // False is 0
    */

    /* <ex2> */
    // 0이외는 다 true라는 성질 이용
    int i = 5;
    while (i)
        printf("%d is ture\n", i--);    // 5 is ture
                                        // 4 is ture
                                        // 3 is true   
                                        // 2 is true
                                        // 1 is true
    printf("%d is false\n", i);         // 0 is false

    /* <ex3> */
    // 무한 루프 코드
    while(1)
    {

    }
    
    return 0;
}