/* 표준 유틸리티 라이브러리 */

#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

/*
    rand(), srand(), malloc(), free(), ...
*/

void goodbye(void)
{
    printf("Goodbye\n");
}

void thankyou(void)
{
    printf("Thankyou\n");
}

_Noreturn void stop_now(int i)  // 함수가 끝난 후 프로그램이 진행되는 흐름으로 돌아가지 않고 끝난다.
{
    if (i > 0) exit(i);
    // exit(i);
}
int main()
{
    printf("Purchased?\n");
    if (getchar()== 'y')
        atexit(thankyou);   // atexit() : 프로그램이 종료될 때 어떤 함수가 호출될지 정해줄 수 있다. (runtime에 추가가된다.)
                            // thankyou라는 함수의 포인터를 통해서 함수의 내용을 실행 

    while (getchar() != '\n') {};

    printf("Goodbye message ?\n");
    if (getchar() == 'y')
        atexit(goodbye);

    /*
        exit(0);
    */

    /*
        qsort();
    */

    puts("preparing to stop ...");
    stop_now(2);
    puts("This code is never executed.");

    return 0;
}