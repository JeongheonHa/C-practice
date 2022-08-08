/* memcpy() and memmove() */
// 메모리의 내용을 copy and move하는 함수
// 문자열, 메모리를 복사할 때 자주 사용

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy(), memmove() 

#define LEN 6

void prt(int *arr, int n)
{
    for (int i =0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    /*
        - overlapping region
        - pointer-to-void (datatype is unknown)
    */

    int arr1[LEN] = { 1, 3, 5, 7, 9, 11 };
    int* arr2 = (int*)malloc(LEN * sizeof(int));
    if (arr2 == NULL) exit(1);

    // <1> memcpy를 이용하지 않고 하나하나 복사
    for (int i = 0; i < LEN; ++i)
        arr2[i] = arr1[i];

    // <2> 메모리 자체를 복사 *권장*
    memcpy(arr2, arr1, sizeof(int) * LEN);  // 얼마 만큼의 사이즈를 복사할지 알려주고 arr1의 메모리를 arr2로 복사
    prt(arr2, LEN);

    /*
        memcpy vs memove 차이
    
        { 1, 3, 5, 7, 9, 11 }
        { 5, 7, 9, 11, 9, 11 }

        // 5, 7이 겹친다.
    */

    // memcpy(arr1, &arr1[2], sizeof(int) * 4); // 같은 배열안의 내용을 복사할 때 겹치는 부분이 발생할 경우 memcpy는 문제가 발생한다.
    memmove(arr1, &arr1[2], sizeof(int) * 4);   // 겹치는 부분이 발생해도 문제가 발생하지 않는다.
    prt(arr1, LEN);

    return 0;
}