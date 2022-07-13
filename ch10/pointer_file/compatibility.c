/* 포인터의 호환성 */

#include <stdio.h>

int main()
{
    // int n = 5;
    // double x;
    // x = n;
    // int* p1 = &n;
    // double* pd = &x;
    // // pd = p1; // warning 포인터를 복잡하게 만든 코드는 좋은 코드가 아니다.

    // int* pt;
    // int(*pa)[3];    // 원소가 3개인 배열에 대한 포인터
    // int ar1[2][3] = {3, };  // 원소가 3개인 배열의 2개의 배열
    // int ar2[3][2] = {7, };
    // int** p2;

    // pt = &ar1[0][0];
    // pt = ar1[0];
    // // pt = ar1;    // warning, ar1은 이중 배열이기때문에 그냥 포인터에는 담을 수 없다. 
    // pa = ar1;   // 원소가 3개인 배열이기 때문에 대입 가능
    // // pa = ar2;    // warning
    // p2 = &pt;
    // *p2 = ar2[0];
    // // p2 = ar2;    // warning

    // // <주의 사항>
    // // p2 : pointer to pointer to int
    // // ar2 : a pointer to array-of-2-ints

    /* pointer and const */

    // <1>
    // int x = 20;
    // const int y = 23;
    // int* p1 = &x;
    // const int* p2 = &y;
    // const int** pp2 = &p1;
    // // p1 = p2;     // warning 

    // // *p2 = 123;   // error
    // p2 = p1;    // 고정 시키고 싶다면 const int* const p2 = &y; 입력

    // int x2 = 30;
    // int* p3 = &x2;
    // *pp2 = p3;  // 고정 시키고 싶다면 const int* const * pp2 = &p1; 입력
    // pp2 = &p1;  // 고정 시키고 싶다면 const int** const pp2 = &p1; 입력

    // <2>  이런 상황을 만들지 않도록 한다.
    const int** pp2;
    int* p1;
    const int n = 13;
    pp2 = &p1;
    *pp2 = &n;
    *p1 = 10;   // visualstudio에서는 const int n = 13;이지만 값이 10으로 바뀐다.
                // c++ compiler는 warning (vscode는 c++에 좀 더 가깝기 때문에 warning)
}