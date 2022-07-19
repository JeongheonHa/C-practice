/* static variables vith external linkage */
// 정적 변수의 외부 연결 (흔히 전역 변수라고 말한다)
/*  
    storage class       memory segment      duration        scope       linkage         how declared
    ----------------------------------------------------------------------------------------------------------------
    고정적, 외부 연결       데이터 or BSS           고정적         파일 안        번역 단위의         모든 함수들 밖
    (static with external linkage)                                       외부로도 연결 가능
    ----------------------------------------------------------------------------------------------------------------
*/
// scope는 파일 안이지만 모든 함수들의 밖에서도 사용 가능하다.

#include <stdio.h>

/*
    Static variable with external linkage
    - File scope, external linkage, static storage duration
    - External storage class
    - External variables
*/

// static variables은 초기화를 하지않을 경우 한번에 초기화를 해준다.
// int g_int;

int g_int = 0;   // 권장, file scope에서 second.c 파일에 있는 extern int g_int; 둘 중에 하나만 초기화 해야한다.
double g_arr[1000] = { 0.0, };

/*
    Initializing External Variable
*/

int x = 5;  // 가능, constant expression
int y = 1 + 2;  // 가능, constant expression
size_t z = sizeof(int); // 가능, sizeof is a constant expression
// int x2 = 2 * x;  // 불가능, x is a variable

void func()
{
    printf("g_int in fun() %d %p\n", g_int, &g_int);
    g_int += 10;
}

void fun_sec(); // 선언만 해주면 linker가 알아서 찾아준다.

int main()
{
    /*
        defining declaration vs referencing declaration
    */

    extern int g_int;    // 외부에서 g_int라는 변수를 가져와라, 같은 변수를 아래에 선언할 수 없다.(referencing declaration) *권장*
                         // 현재는 file scope 영역안에서 가져오는 중
    // extern int g_int = 1024;

    // int g_int = 123; // hides global variable g_int (defining declaration)

    extern double g_arr[];
    printf("g_int in main() %d %p\n", g_int, &g_int);   // g_int in main() 0 0x1026cc010
    g_int += 1;

    func(); // g_int in fun() 1 0x1026cc010
    fun_sec();

    return 0;
}