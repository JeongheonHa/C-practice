/* 배열을 이용한 포인터 */
// 포인터가 배열을 대체할 수 있다.

#include <stdio.h>

int main()
{
    int arr[10];

    int const num = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < num; ++i)
        arr[i] = (i + 1) * 100;

    // int* ptr = arr; // 배열의 첫 주소를 ptr에 대입

    // printf("%p %p %p\n", ptr, arr, &arr[0]);    // 0x16cee34e0 0x16cee34e0 0x16cee34e0
    // // %p : 입력을 포인터 (주소)로 해석(16진수)
    // ptr += 2;    // 배열의 대표주소에서 2 더한 주소를 포인터에 저장

    // printf("%p %p %p\n", ptr, arr + 2, &arr[2]);    // 0x16dcf34c8 0x16dcf34c8 0x16dcf34c8

    // // arr += 2;    // pointer끼리 산술연산하는 것은 가능하지만 배열은 안된다. 배열의 대표주소가 바뀌는 것이므로 안된다.
    
    // printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);   // 400 400 400

    /* <ex> 일반적인 pointer 사용 */

    int *ptr = arr;
    for (int i = 0; i < num; ++i)
    {
        printf("%d %d\n", *ptr++, arr[i]);  // ptr이 하나씩 증가하면서 출력, 100 200 300 400 이런식의 출력
                                            // ptr의 dereferencing한 값을 접근해서 출력 후 후의 연산자로 인해 ptr의 값(주소 arr) 증가
        printf("%d %d\n", *(ptr + i), arr[i]);  // 첫 주소 ptr에서 i만큼 건너뛰어서 출력 (위의 식과 동일)
        printf("%d %d\n", *ptr + i, arr[i]);    // 100 + 1, 100 + 2 이런식의 출력
    }
    return 0;
}