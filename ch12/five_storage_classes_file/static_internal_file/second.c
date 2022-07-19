#include <stdio.h>

extern int g_int;   // referencing declaration, defining declaration되어있는 곳에서 g_int를 사용

void fun_second()
{
    g_int += 1;
    printf("g_int int fun_second() %d %p\n", g_int, &g_int);
}