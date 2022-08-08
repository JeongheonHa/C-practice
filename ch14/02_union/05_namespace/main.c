/* 이름공간 공유하기 */
// 대부분 이름이 같으면 헷갈리기 때문에 이름을 다르게 지정한다.

#include <stdio.h>

// <4>
int function()
{
    return 0;
}

// <5>
// int a = 123;    // 컴파일 할때는 translation unit이 file단위이기 때문에 넘어갔지만 runtime에서 이름이 충돌하여 error

int main()
{
    /*
        namespace
        - Identify parts of a program in which a name is recognized
        - You can use the same name for one variable and one tag
        - C++ : use 'namespace' to use the same identifiers in the duplicated scopes
    */

    // <1>
    // 같은 scope안에 이름이 같은 변수를 선언할 수 없다.
    {
        int myname = 345;
        // double myname = 3.14; // error
    }

    // <2>
    // 태그와 변수는 다른 카테고리이기 때문에 이름이 같을 수 있다.
    struct rect { double x; double y; };

    // int rect = 123;  // OK in C (NOT OK in C++)
    struct rect rect = { 1.1, 2.2 };    // sturct rect and rect are in different categories

    // <3>
    // 컴파일러 입장에서 한번 생각해보기
    // typedef struct rect rect;
    // rect rect = { 1.1, 2.2 };    // NOT OK

    // <4>
    // int function = function();   // error , 함수와 같은이름의 변수를 선언할 수 없다. (이름이 충돌)

    // <5>
    /*
        namespace pollution
        - Names in different files accidentally conflicting with each other
    */

    // printf("%d\n", a);   //other.c
}