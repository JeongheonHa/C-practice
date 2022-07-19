// 함수에 static 키워드를 사용한 경우 해당 파일 내에서만 사용

#include <stdio.h>

extern int g_int2;

static void tool()  // tool()함수를 fun_second()함수를 통해서만 사용하고 싶을 경우 tool()함수에 static 키워드를 사용하여 해당 파일내에서는 fun_second()함수를
                    // 통해 사용할 수 있지만 다른 파일에서 tool()함수를 불러올 수 없다.
{
    //
}

static void fun_second();   // 프로토타입에 static 키워드를 사용해도 body가있는 함수에 적용된다.

void fun_second()    
{
    tool();

    g_int2 += 1;
    printf("g_int2 in fun( %d %p\n", g_int2, &g_int2);
}