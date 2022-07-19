/* 함수의 저장 공간 분류 */

#include <stdio.h>

/* 
    Storage Classes and Functions
    - Functions external (by default) or static
    - A function declaration is assumed to be extern
*/
// function은 맨 처음에 프로그램과 함께 loading이 되며 계속 있는다.
int g_int2 = 123;

extern void fun();  // 원래는 함수의 선언앞에 extern이 붙어있는 형태이다.(생략해서 사용하는 것이다)
extern void fun_second();

int main()
{
    fun();
    fun_second();
    // tool();  // 사용할 수 없다.

    return 0;
}

void fun()
{
    extern int g_int2;

    g_int2 += 1;
    printf("g_int2 in fun( %d %p\n", g_int2, &g_int2);
}

