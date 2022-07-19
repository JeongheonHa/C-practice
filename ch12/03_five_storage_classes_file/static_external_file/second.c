#include <stdio.h>

extern int g_int;   // main파일에서의 int g_int = 0;을 가져다 쓰는 방법

void temp()
{
    // extern int g_int; // 가능, 전역변수로 선언하는거 대신 block scope에서 선언 가능
    // extern int g_int = 123;
    g_int += 1000;
}

void fun_sec()
{
    temp();

    //  extern int g_int = 123; // X, block scope에서는 초기화를 할 수 없다.
                                // stack의 stack frame이 생성된 곳에서 data segment와 관련된 작업을 하는 것이다.

    g_int += 7;
    printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}