/* 2차원 배열과 포인터 */

#include <stdio.h>

int main()
{
    // float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

    // printf("%llu\n", (unsigned long long)arr2d);
    // printf("%llu\n", (unsigned long long)arr2d[0]); // & arr2d[0]와 같다.
    // printf("\n");
    // // arr2d가 가리키는 주소는 arr2d[0]이다 (not arr2d[0][0]), arr2d : arr2d[0][0]의 주소 , arr2d[0][0] : 값

    // printf("%llu\n", (unsigned long long)* arr2d);  // * arr2d를 하면 arr2d[0]이 나온다.
    // printf("%llu\n", (unsigned long long)& arr2d[0]);
    // printf("%llu\n", (unsigned long long)& arr2d[0][0]);
    // printf("%f %f\n", arr2d[0][0], **arr2d);    //값을 출력
    // printf("\n");

    // // 아래 값들 모두 같은 주소를 의미
    // printf("%llu\n",(unsigned long long)(arr2d + 1));
    // printf("%llu\n",(unsigned long long)(&arr2d[1]));
    // printf("%llu\n",(unsigned long long)(arr2d[1]));
    // printf("%llu\n",(unsigned long long)(*(arr2d + 1)));
    // printf("%llu\n",(unsigned long long)(&arr2d[0] + 1));
    // printf("%llu\n",(unsigned long long)(&arr2d[1][0]));
    // printf("\n");

    // printf("%f\n", *(*(arr2d + 1) + 2));
    // printf("\n");

    // for (int j = 0; j < 2; ++j)
    // {
    //     printf("[%d] = %llu, %llu\n", j, (unsigned long long)(arr2d[j]), (unsigned long long) * (arr2d + j));

    //     for (int i = 0; i < 4; ++i)
    //     {
    //         printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));

    //         *(*(arr2d + j) + i) += 1.0f;
    //     }
    // }
    // printf("\n");

    /* pointer to multidimensional arrays */

    float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f}};

    float (*pa)[4]; // 4개의 float를 가진 배열에 대한 포인터 (포인터 하나)
    float* ap[2];   // 원소가 2개인 포인터의 배열

    printf("%zu\n", sizeof(pa));    // 8 in x64
    printf("%zu\n", sizeof(ap));    // 16 in x64
    printf("\n");

    pa = arr2d; // 첫번째 주소 대입 가능
    // pa[0] = arr2d[0];    // error, 포인터가 하나이기 때문에 배열처럼 사용 X
    // pa[1] = arr2d[1];    // error

    // ap = arr2d;  // error
    ap[0] = arr2d[0];   // 가능
    ap[1] = arr2d[1];   // 가능

    // float (*pa)[4]
    printf("%llu %llu\n", (unsigned long long)pa, (unsigned long long)(pa + 1));    // pa : 주소 자체를 대입
    printf("%llu %llu\n", (unsigned long long)arr2d[0], (unsigned long long)arr2d[1]);
    printf("%llu %llu\n", (unsigned long long)pa[0], (unsigned long long)(pa[0] + 1));
    printf("%f\n", pa[0][0]);
    printf("%f\n", *pa[0]);
    printf("%f\n", **pa);
    printf("%f\n", pa[1][3]);
    printf("%f\n", *(*(pa + 1) + 3));
    printf("\n");

    // float* ap[2]
    printf("%llu %llu\n", (unsigned long long)ap, (unsigned long long)(ap + 1));    // ap : 포인터를 담는 배열이 새로 생견난 것
    printf("%llu %llu\n", (unsigned long long)arr2d[0], (unsigned long long)arr2d[1]);
    printf("%llu %llu\n", (unsigned long long)ap[0], (unsigned long long)(ap[0] + 1));
    printf("%f\n", ap[0][0]);
    printf("%f\n", *ap[0]);
    printf("%f\n", **ap);
    printf("%f\n", ap[1][3]);
    printf("%f\n", *(*(ap + 1) + 3));
    printf("\n");

    
}   