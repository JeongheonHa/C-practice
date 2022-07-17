/* 이차원 배열과 메모리 */

#include <stdio.h>

int main()
{
    int arr[2][3] = { {1, 2, 3},
                      {4, 5, 6} };

    // // int arr[2][3] = { 1, 2, 3,
    // //                   4, 5, 6 };
    // // int arr[2][3] = { 1, 2 };   // 나머지 0으로 초기화 

    // printf("%d\n\n", arr[1][1]);

    // for (int j = 0; j < 2; ++j) // 2차원 배열을 반복문으로 돌릴 때 j를 바깥쪽 루프
    // {
    //     for (int i = 0; i < 3; ++i) // i를 안쪽 루프
    //         printf("%d ", arr[j][i]);

    //     printf("\n");
    // }
    // printf("\n");    

    /* 2차원 배열의 크기 */

    int *ptr = &arr[0][0];  // arr를 ptr로 바꾸고 1차원 배열인 것 처럼 사용 가능
    // int *ptr = arr[0], 같은 식
    // int *ptr = arr; , error
    
    for (int k = 0; k < 6; ++k)
        printf("%d ", ptr[k]);   // ptr[k] : ptr변수의 k번째 값, 변수의 메모리 공간에는 2차원 배열의 첫번째 주소가 담겨있다. ->  첫번째 주소의 k번째 값
    printf("\n\n");

    printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));   // 24 12, arr[0]의 경우 0행의 배열 3개의 사이즈

    return 0;

    /* 연습 문제 */

//     int const MONTHS = 12;
//     int const YEARS = 3;
//     double year[YEARS][MONTHS] = 
//     {
//         {-0.9, 1.0, 7.1, 12.1, 19.4, 22.5, 25.9, 27.2, 22.6, 16.4, 7.6, 1.4},
//         {1.6, 2.5, 7.7, 11.1, 18.0, 23.9, 24.1, 26.5, 21.4, 14.3, 8.0, -0.4},
//         {-2.4, 2.7, 9.0, 14.2, 17.1, 22.8, 28.1, 25.9, 22.6, 15.6, 8.2, 0.6}
//     };
//     // <1>
//     printf("[Temperature Data]\n");
//     printf("year index : ");
//     for (int m = 0; m < MONTHS; ++m)
//     {
//         printf("\t%d ", m + 1);
//     }
//     printf("\n");

//     for (int y = 0; y < YEARS; ++y)
//     {

//         printf("year %d\t   : ", y);
//         for (int i = 0; i < MONTHS; ++i)
//         {
//             printf("\t%.1f", year[y][i]);
//         }
//         printf("\n");
//     }
//     printf("\n");

//     // <2>
//     printf("[Yearly average temperatures of 3 years]\n");
//     for (int y = 0; y < YEARS; ++y)
//     {
//         double avg_temp = 0.0;

//         for (int m = 0; m < MONTHS; ++m)
//         avg_temp += year[y][m];

//         avg_temp /= (double)MONTHS;

//         printf("year %d : average temperature = %.1f\n", y, avg_temp);
//     }
//     printf("\n");

//     // <3> 
//     printf("[Monthly average temperatures for 3 years]\n");
//     printf("year index : ");
//     for (int m = 0; m < MONTHS; ++m)
//     {
//         printf("\t%d ", m + 1);
//     }
//     printf("\n");

//     printf("avg  temps : ");
//     for (int m = 0; m < MONTHS; ++m)
//     {
//         double avg_temp = 0;
//         for (int y = 0; y < YEARS; ++y)
//         {
//             avg_temp += year[y][m];
//         }
//         avg_temp /= (double)YEARS;
//         printf("\t%.1f ", avg_temp);
//     }
//     printf("\n");
    
//     return 0;
}


