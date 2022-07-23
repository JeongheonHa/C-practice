/* 자료형 한정자들 */
// const, volatile, restrict

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
        Qualified types
        const, volatile, restrict, _Atomic
    */

    /*
        const
    */

    // <1>
    const const const int n = 6;    //const를 여러번 사용할 수 있다.

    typedef const int zip;
    const zip q = 8;    // 사실상 const const int zip 이기 때문에 const가 안되는 것을 방지
    
    // <2>
    // const int i; // 초기화가 안되있는 상태에서 const를 하면 i를 사용할 수 없다.
    // i = 12;  // error
    // printf("%d\n", i);   // error

    // <3>
    const int j = 123;
    const int arr[] = {1, 2, 3};

    // <4>
    float f1 = 3.14f, f2 = 1.2f;
    
    const float* pf1 = &f1;
    // *pf1 = 5.0f; // error 
    pf1 = &f2;  // 가능

    float* const pf2 = &f1;

    *pf2 = 6.0f;
    // pf2 = &f2;   // error

    const float* const pf3 = &f1;
    // *pf3 = 7.0f; // error 
    // pf3 = &pf2;   // error

    /*
        global constants
    */
    // PI 등 전역으로 사용되는 값을 const를 하고싶을 때는 따로 header file을 만들어 #include " "를 사용하는 것이 유용하다.

    /*
        volatile (불안한, 휘발성의, 변덕스러운)
        - Do not optimize
        - (ex : hardward clock)
    */
    // 변수 vi의 값을 컴파일러가 모르는 상황에서 해당 프로그램이 아닌 다른 것에의해 값이 바뀔 수 있으니 최적화 하지마라 (바뀌게 둬라)

    volatile int vi = 1;
    volatile int* pvi = &vi;

    int i1 = vi;    // 운영체제가 컴파일러 모르게 값을 바꾸는 경우도 있다. ex) cashing (임시 저장공간에 저장해놓아서 속도를 빠르게 하는 것)
                    // volatile 키워드를 사용할 경우 이러한 경우를 막는다.
    // ...

    int i2 = vi;

    /* 
        restrict (_restrict in VS)
        - solo initial means of accessing a data object
        - compiler can't check this restriction (사용자가 지켜야한다.)
    */

    int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int * par = ar;

    int* restrict restar = (int*)malloc(10 * sizeof(int));  // 동적 할당을 통해 받아온 메모리를 오직 restar 변수를 통해서만 접근 하겠다는 의미
    if (!restar) exit(1);

    // <1>
    // 두 코드가 같은 의미이지만 변수명이 다르기때문에 컴파일러가 아래와 같이 최적화를 하고싶어도 하지 못한다.
    ar[0] += 3;
    par[0] += 5;
    // par[0] += 8;

    // <2>
    // 아래와 같이 최적화 할 수 있다.
    restar[0] += 3;
    restar[0] += 5;
    // restar[0] += 8;  

}