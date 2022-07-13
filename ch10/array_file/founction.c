/* 배열을 함수에게 전달해주는 방법 */
// // 함수에서 배열을 받을 때는 포인터로 받는다.
// #include <stdio.h>

// /* 프로토타입 선언 유형 */
// /* 
// double average(double *arr, int n);
// double average(double *, int n);    // 다 알아봄.  
// double average(double arr[], int n);    
// double average(double [], int n);   // // 나중에 코드를 볼때 배열을 받는 함수다는 것을 표현하기위해 []를 사용
// */
// double average(double arr[], int n);

// int main()
// {
//     double arr1[5] = {10, 13, 12, 7, 8};
//     // double arr2[5] = {1.8, -0.1, 6.3, 13.9, 20.2};
//     double arr2[3] = {1.8, -0.2, 2.3};   // 길이가 3인 배열에 3개의 값만이 존재하고 나머지 3, 4번째에는 어떤 값이 존재하는 지 알 수 없으므로
//                                          // 이상한 값까지 더해서 평균을 내서 이상한 값이 나온다.
//     printf("Address = %p\n", arr1);
//     printf("Size = %zd\n", sizeof(arr1));

//     printf("Address = %p\n", arr2);
//     printf("Size = %zd\n", sizeof(arr2));

//     printf("Avg = %f\n", average(arr1, 5));
//     printf("Avg = %f\n", average(arr2, 3));

//     return 0;
// }

// double average(double arr[], int n)  // arr배열의 첫번째 주소만을 함수로 불러오기때문에 []안의 배열의 길이는 의미가 없다.
//                                      // 따라서 배열의 길이는 따로 변수로 만들어야한다. (int n)
// {
//     printf("Size = %zd in founction average\n", sizeof(arr));   // 64bit 기준 기본 주소 사이즈인 8출력, 내부적으로 arr은 포인터처럼 처리가 되고있다.

//     double avg = 0.0;
//     for (int i = 0; i < n; ++i)
//     {
//         avg += arr[i];
//     }
//     avg /= (double)n;

//     return avg;
// }

/* 두개의 포인터로 배열을 함수에게 전달 */

#include <stdio.h>

double average(double* start, double* end);

int main()
{
    double arr1[5] = {10, 13, 12, 5, 4};

    printf("Avg = %f\n", average(arr1, arr1 + 5));

    return 0;
}

double average(double* start, double* end)
{
    int count = end - start;
    double avg = 0.0;
    while (start < end)
    {
        avg += *start++;
        // count++; // while문 안에서 증가시키는 것이 부담일 경우 count변수 선언할때 end - start를 대입
    }
    avg /= (double)count;

    return avg;
}