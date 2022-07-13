/* 복합 리터럴과 배열 */
// 간단한 배열의 경우, 배열의 원소들을 직접 입력해줘야하는 경우 (하드코딩을 해줘야하는 경우) 유용하게 사용 가능

#include <stdio.h>

#define COLS 4
int sum_1d(int arr[], int n);
int sum_2d(int arr[][COLS], int rows);

int main()
{
    // <literal의 예>
    // int a = 1;
    // 3;  // Literals are constants that aren't symbolic
    // 3.14f;

    // int b[2] = {3, 4};  
    // (int[2]) {3, 4};    // compound literal, 배열을 compound literal로 표현하면 이름이 없는 이런 형태

    // int c[2] = (int[2]){3, 4};   // Error, 복합 리터럴로 배열을 초기화하는 것은 안된다.

    // <실질적인 예>
    // <1>  배열의 경우
    int arr1[2] = {1, 2};
    int arr2[2][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

    printf("%d\n", sum_1d(arr1, 2));
    printf("%d\n", sum_2d(arr2, 2));
    printf("\n");

    printf("%d\n", sum_1d((int[2]) {1, 2}, 2)); // compound literal을 이용해 배열을 literal처럼 바로 넣을 수 있다.
    printf("%d\n", sum_2d((int[2][COLS]) { {1, 2, 3, 4}, {5, 6, 7, 8} }, 2));
    printf("\n");

    // <2>  포인터의 경우
    int* ptr1;
    int(*ptr2)[COLS];

    ptr1 = (int[2]){1, 2};
    ptr2 = (int[2][COLS]){ {1, 2, 3, 4}, {5, 6, 7, 8} };

    printf("%d\n", sum_1d(ptr1, 2));
    printf("%d\n", sum_2d(ptr2, 2));
    printf("\n");

    return 0;
}

int sum_1d(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += arr[i];
    return total;
}

int sum_2d(int arr[][COLS], int rows)
{
    int total = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < COLS; c++)
            total += arr[r][c];
    return total;
}