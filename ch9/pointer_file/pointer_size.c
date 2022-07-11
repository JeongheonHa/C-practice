/* 포인터 변수의 크기 */
// x64를 사용중이기 때문에 기본 주소의 메모리가 8byte (1byte = 8bit, 8byte = 64bit)
// 메모리 주소를 저장한 변수 ptr_은 기본 주소의 메모리가 할당된다.

#include <stdio.h>

int main()
{
    char a;
    float b;
    double c;

    char* ptr_a = &a;
    float* ptr_b = &b;
    double* ptr_c = &c;

    printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));   // 1 4 8
    printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));   // 8 8 8
    printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));    // 8 8 8
    printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*));    // 8 8 8
}