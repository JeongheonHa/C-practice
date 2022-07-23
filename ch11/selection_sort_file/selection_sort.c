/* 선택 정렬 */
// https://www.geeksforgeeks.org/selection-sort/
// 오름차순 정렬
// #include <stdio.h>

// void swap(int* xp, int* yp);
// void printArray(int arr[], int size);
// void selectionSort(int arr[], int n);

// int main()
// {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     selectionSort(arr, n);

//     printArray(arr, n);

//     return 0;
// }

// void swap(int* xp, int* yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }

// void printArray(int arr[], int size)
// {
//     for (int i = 0; i < size; ++i)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// void selectionSort(int arr[], int n)
// {
//     int min;
//     for (int i = 0; i < n - 1; ++i)
//     {
//         min = i;
//         for (int j = i + 1; j < n; ++j)
//         {
//             if (arr[j] < arr[min])
//             {
//                 min = j;
//             }
//         }
//         swap(&arr[i], &arr[min]);
//     }
// }

/* 선택정렬을 이용한 문자열 정렬 */

#include <stdio.h>
#include <string.h>

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
    char* arr[] = {"Cherry", "AppleBee", "Pineapple","Apple", "Orange"};
    int n =  sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);

    printStringArray(arr, n);

    return 0;
}

void printStringArray(char* arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%s\n", *(arr + i));
    }
}

void selectionSort(char* arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; ++i)
    {
        min_idx = i;
        for (j = i + 1; j < n; ++j)
        {
            if (strcmp(arr[j], arr[min_idx]) < 0)
            min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);   // 포인터 자체의 주소
    }
}

void swap(char** xp, char** yp)
{
    char* temp = *xp;   // 포인터가 가리키는 문자열 주소 바꿈
    *xp = *yp;
    *yp = temp;
}