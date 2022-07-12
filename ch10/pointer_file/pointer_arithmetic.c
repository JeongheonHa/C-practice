/* 포인터의 산술 연산 (pointer arithmetic) */

// #include <stdio.h>

// int main()
// {
//     int* ptr = 0;

//     printf("%p %lld\n", ptr, (long long)ptr);   // 0x0 0

//     ptr += 1;   // ptr변수의 자료형 만큼을 더하는 연산, -=, ++, --, -, +

//     printf("%p %lld\n", ptr, (long long)ptr);   // 0x4 4

//     // ptr = -ptr; // X
//     // ptr = +ptr; // X

//     /* subtraction */
//     double arr[10];
//     double* ptr1 = &arr[3], * ptr2 = &arr[5];

//     // ptr2 = ptr1 + ptr2;   // X 포인터끼리 더하기 안됨
//     int i = ptr2 - ptr1;  // 가능, 주어진 사이즈만큼 몇 칸 차이(i)가 나는가
//                           // 뺀 값을 double의 메모리 값으로 나누어서 몇 칸 떨어져있는지 계산
    
//     printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);
   
//     return 0;
// }

/* 포인터 연산 총정리 */

#include <stdio.h>

int main()
{
    int arr[5] = {100, 200 ,300 ,400 ,500};
    int * ptr1, * ptr2, *ptr3;

    // ptr1 = arr; // assignment

    // printf("%p %d %p\n", ptr1, *ptr1, &ptr1);   // dereferencing, taking a pointer address

    // ptr2 = &arr[2]; // address of operator &

    // printf("%p %d %p\n", ptr2, *ptr2, &ptr2);

    // ptr3 = ptr1 + 4;    // adding an integer from a pointer

    // printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    // // differencing
    // printf("%td\n", ptr3 - ptr1);   // t : 형식지정자에 t가 들어갈 경우 포인터의 차이를 입력 받는다. (int형으로도 가능하나 형식적으로 t 사용)

    // ptr3 = ptr3 - 4;    // subtracing an integer from a pointer

    // ptrintf("%p %d %p\n", ptr3, *ptr3, &ptr3); 

    // ptr1++;
    // ptr1--;
    // --ptr1;
    // ++ptr1;

    // 포인터 끼리 비교
    if (ptr1 == ptr3)
        printf("Same\n");
    else
        printf("Different\n");

    // 정수형이 다른 포인터 끼리의 비교
    double d = 3.14;
    double* ptr_d = &d;

    if (ptr1 == ptr_d)  // 둘다 주소를 저장하고 있기때문에 저장하는 사이즈는 같다. 정수형이 다른 포인터 끼리의 비교가 가능은 하지만, 대부분 작성자의 실수이다.
        printf("Same\n");
    else
        printf("Different\n");

    return 0;
}