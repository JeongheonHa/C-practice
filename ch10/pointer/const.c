/* 배열과 포인터에서 const */

#include <stdio.h>

int main()
{
    // type qualifiers: const, volatile, ..

    const double PI = 3.141592;
    // PI = 2.141592;   // const로인해 값 변환 X

    const double arr[5] = {1, 2, 3, 4, 5};
    // arr[1] = 123;    // 배열의 각각의 값 변환 X

    const double arr2[4] = {1.0, 2.0, 3.0, 4.0};    // 배열 각각의 원소 값 변경 X

    const double* pd = arr2;    // 배열의 각각의 원소 값 변경 X
    // *pd = 3.0;  // pd[0] = 3.0; , arr2[0] = 3.0; 모두 같은 의미 (const할 경우 대입 X)
    // pd = arr; , 포인터 값 변경 가능, (const pd를 할 경우 X)
    // pd[2] = 1024.0; // arr2[2] = 1024.0; 같은 의미 (const할 경우 대입 X)

    printf("%f %f\n", pd[2], arr2[2]);  // 3.000000 3.000000

    pd++;   // 주소의 값을 증가시키는 것은 가능, const pd를 할 경우 pd++ 사용 X (주소 변경 X)

    printf("%f %f\n", pd[2], arr2[2]);  // 4.000000 3.000000

    return 0;

}

/* 배열 매개변수와 const */

// #include <stdio.h>


// void print_array(const int arr[], const int n)
// {
//     for (int i = 0; i < n; ++i)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// void add_value(int a[], const int n, const int val)   // 주소에 값을 일일이 더해주고 있기 때문에 return 값이 없어도 있는 것과 같은 기능을 한다.
//                                                       // int a[]는 배열의 첫번째 주소(인자)를 매개변수로 가져와 사용
// {
//     int i;
//     for (i = 0; i < n; i++)
//         a[i] += val;    // a[i] : 포인터 변수 a에 저장되있는 값은 배열의 주소 arr이므로 arr[i]로 볼 수 있다. (배열에 직접 접근)
// }

// int sum(const int ar[], const int n)  // const를 함으로서 미리 의도를 명확히 하여 실수를 방지할 수 있다.
// {
//     int i = i;
//     int total = 0;

//     for (i = 0; i < n; i++)
//         total += ar[i]; //++; 수정 후

//     return total;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     const int n = sizeof(arr) / sizeof(arr[0]);

//     print_array(arr, 5);    // 1 2 3 4 5 
//     add_value(arr, 5, 100); 
//     print_array(arr, 5);    // 101 102 103 104 105 

//     int s = sum(arr, n);
//     printf("Sum is %d\n", s);
//     print_array(arr, 5);    // 102 103 104 105 106 , sum함수의 ar[i] ++로인해 발생한 실수

//     return 0;
// }