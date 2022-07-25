/* 복잡한 함수 선언 이해하기 */
// 실제로는 typedef를 이용해 이해하기 쉬운 형태로 바꿔서 코딩을 하는 것이 일반적이다.

#include <stdio.h>

int temp(int a)
{
    return 0;
}

int (*g(int a))(int)
{
    return temp;
}

int main()
{
    /*
        *  indicates a pointer
        () indicates a function
        [] indicates an array
    */

    /*
        <규칙>
        - 안쪽에서부터 바깥쪽으로 읽어라
        - *(asterisk)보다 [], ()가 우선순위가 높다.
    */

    int* ap[10];    // 1. 이름을 먼저 찾는다. -> [] -> int* (int포인터 10개짜리 배열)

    typedef int* pint;
    pint ap2[10];

    float* fp(float);   // fp is a function that returns a pointer

    typedef float* pfloat;
    pfloat fp2(float);

    void (*pf)(int);
    /*
        void (*pf)(int);
               1         1. pointer to
                    2    2. function with int arguement
         3               3. returning void
    */

    int* (*x[10])(void);
    /*
        int* (*x[10])(void);
                 1            1. array of
              2               2. pointers to
                       3      3. functions with no arguments
         4                    4. returning pointer to int
    */


    /* 잘못된 예 */

    /* 1. A function can't return an array */

    // int f(int)[];    // wrong

    /* But it can return a pointer to an array */

    int(*f(int))[];

    /* 2. A function can't return a function */

    // int g(int)(int); // wrong

    /* But it can retur a pointer to a function */

    int (*g(int))(int);

    /* 3. An array of functions aren't possible */

    // int a[10](int);  // wrong

    /* But an array of function pointers are possible */
    int (*x2[10])(int);

    /* Using typedef to simplify declarations */

    typedef int FCN(int);
    typedef FCN* FCN_PTR;
    typedef FCN_PTR FCN_PTR_ARRAY[10];
    FCN_PTR_ARRAY x3;


}