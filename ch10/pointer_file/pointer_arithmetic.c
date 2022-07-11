/* 포인터의 산술 연산 (pointer arithmetic) */

#include <stdio.h>

int main()
{
    int* ptr = 0;

    printf("%p %lld\n", ptr, (long long)ptr);   // 0x0 0

    ptr += 1;   // ptr변수의 자료형 만큼을 더하는 연산, -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);   // 0x4 4

    // ptr = -ptr; // X
    // ptr = +ptr; // X

    /* subtraction */
    double arr[10];
    double* ptr1 = &arr[3], * ptr2 = &arr[5];

    // ptr2 = ptr1 + ptr2;   // X 포인터끼리 더하기 안됨
    int i = ptr2 - ptr1;  // 가능, 주어진 사이즈만큼 몇 칸 차이(i)가 나는가
                          // 뺀 값을 double의 메모리 값으로 나누어서 몇 칸 떨어져있는지 계산
    
    printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);
   
    return 0;
}