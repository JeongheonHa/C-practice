/* 정적 변수의 내부 연결 */
// static variables with internal linkage

/*
    storage class       memory segment      duration        scope       linkage         how declared
    ---------------------------------------------------------------------------------------------------------------- 
    고정적, 내부 연결       데이터 or BSS           고정적         파일 안        번역 단위의         모든 함수들 밖에서
    (static with internal linkage)                                       내부에서만 사용      static 키워드 사용
    ----------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

/*
    static variable with internal linkag
    - File scope, internal linkage, static storage duration
    - Internal storage class
*/

static int g_int = 123;    // defining declaration, file scope안에서만 사용 가능 (해당 파일 외부에서 사용할 경우 linker가 찾지 못한다)

void fun();
void fun_second();
void fun_third();

int main()
{
    fun();  // 124 0x102508000, 주소 모두 동일
    // fun_second();
    // fun_third();

    return 0;
}

void fun()
{
    extern int g_int;
    g_int += 1;
    printf("g_int int fun() %d %p\n", g_int, &g_int);
}

