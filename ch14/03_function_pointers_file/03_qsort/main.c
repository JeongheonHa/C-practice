/* qsort() (quick sort) */

#include <stdio.h>
#include <stdlib.h> // qsort()

int compare(const void* first, const void* second)  // strcmp와 비슷한 구조
{
    if (*(int*)first > * (int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else    
        return 0;
}

int main()
{
    int arr[] = { 8, 2, 5, 3, 6, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);    // 비교하는 것을 함수로 만들고 함수의 포인터를 qsort에 넣어주면 함수 포인터를 통해 정렬을 하게 된다.

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}