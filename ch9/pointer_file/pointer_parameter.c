/* 포인터형 매개변수 */
//  값만 바꾸고 주소를 불러오는 형식

#include <stdio.h>

void swap(int* u, int* v)
{
    // 임시변수 하나 선언 (temp) -> a or b 변수 대입 -> 대입에 사용한 변수 a에 다른 변수 값 b대입
    // a가 저장된 임시변수 (temp)를 b에 대입

    printf("%p %p\n", u, v);    // 0x16d2a74e8 0x16d2a74e4

    int temp = *u;
    *u = *v;
    *v = temp;
}

int main()
{
    int a = 123;
    int b = 456;

    printf("%p %p\n", &a, &b);  // 0x16d2a74e8 0x16d2a74e4
    
    // < a, b변수의 값을 swap >
    
    swap(&a, &b);
    printf("%d %d\n", a, b);    // 456 123

    return 0;
}