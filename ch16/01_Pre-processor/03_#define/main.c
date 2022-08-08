/* 매크로 (#define) */

#include <stdio.h>

/*
    Preprocessor directives(전처리 지시자) begins with # symbol at the beginning of a line.
*/

/*
    Macro
    - An instruction that represents a sequence of instructions in abbreviated form.
*/

/*
    <ex>
    #define         SAY_HELLO        printf("Hello, World!");

    Preprocessor    Macro (name)     body (of replacement list)
    directive

    Macro expansion : 매크로가 바디로 교체가 되는 것
*/

/*
    Object-like macros vs Function-like macros

#define ONE 1           // 기호적 상수를 선언하는 매크로 (object-like macros)
#define SQUARE(X) X*X   // 전처리기 단계에서 SQUARE(X)를 모두 교체를 하기때문에 컴파일러 입장에서는 SQUARE(X)가 있는지 모른다 (function-like macros)
*/

#define PI 3.141592     /* Symbolic (or manifest) constants */
#define FRAVITY 9.8

#define THREE 3
#define MESSAGE "The greatest glory in living lies not in never failing, \
but in rising every time we fail."

#define NINE THREE*THREE                        // 매크로를 이용해서 매크로를 선언할 수 있다. (권장하지 않음, 매크로 사용은 최소화하는 것이 좋다)
#define SAY_HELLO printf("Hello, World!\n");    // 명령문을 매크로로 선언 가능
#define FORMAT "Number is %d.\n"                // 포맷 형식 부분을 매크로로 선언 가능

 # define WITH_BLANK 1  // 빈칸을 넣어도 가능하다 (권장하지 않음)

#define MY_CH 'Z'
#define MY_ST "Z"   // Z\0 (보이지 않는 null character가 하나 있다.)

#define LIMIT 20
const int lim = 50;
static int arr1[LIMIT];
const int LIM2 = 2 * LIMIT;

/*
    Token
#define SIX 3*2
#define SIX 3 * 2
#define SIX 3     *      2
// 해석은 컴파일러(전처리기)에 따라서 달라진다.
*/

/* Redefining Constants */
#define SIX 2*3
#define SIX 2*3
// 문법적으로 가능은 하나 사용하지 않는다. (다른 파일에서 include를 많이 사용해서 가져올 경우 가끔 사용)
// #define SIX 2 * 3 // warning (token이라는 개념때문에)

int main()
{
    int n = THREE;

    SAY_HELLO;  // ;;인 형태이지만 ;가 2개라고 해서 차이는 없다.
    n = NINE;

    printf(FORMAT, n);
    printf("%s\n", MESSAGE);    // replaced
    printf("SAY_HELLO NINE\n"); // Not replaced 문자열 안에 있을 경우 대체가 안된다.

    return 0;
}
