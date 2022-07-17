/* 2차원 배열과 포인터 */

#include <stdio.h>

int main()
{
    // float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} }; // 2중 배열의 경우 배열의 첫 주소들을 arr2d를 통해 c문법이 알려준다.

    // printf("%llu\n", (unsigned long long)arr2d);
    // printf("%llu\n", (unsigned long long)arr2d[0]); // & arr2d[0]와 같다. (배열이기 때문에 arr2d[0]의 주소를 알려주는 것 뿐이다)
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
    float* ap[2];   // 원소가 2개인 포인터의 배열 (원소 : 주소)

    printf("%zu\n", sizeof(pa));    // 8 in x64, arr2d의 첫번째 원소의 주소 사이즈
    printf("%zu\n", sizeof(ap));    // 16 in x64, arr2d[0], arr2d[1]의 첫번째 원소의 주소
    printf("\n");

    pa = arr2d; // 첫번째 주소 대입 가능
    // pa[0] = arr2d[0];    // error, 포인터가 하나이기 때문에 배열처럼 사용 X
    // pa[1] = arr2d[1];    // error

    // ap = arr2d;  // error
    ap[0] = arr2d[0];   // 가능
    ap[1] = arr2d[1];   // 가능

    // float (*pa)[4]
    printf("%llu %llu\n", (unsigned long long)pa, (unsigned long long)(pa + 1));    // 6136525904 6136525920, pa : arr2d 자체를 대입
    printf("%llu %llu\n", (unsigned long long)arr2d[0], (unsigned long long)arr2d[1]); // 6136525904 6136525920
    printf("%llu %llu\n", (unsigned long long)pa[0], (unsigned long long)(pa[0] + 1)); // 6136525904 6136525908
    printf("%f\n", pa[0][0]);
    printf("%f\n", *pa[0]);
    printf("%f\n", **pa);
    printf("%f\n", pa[1][3]);
    printf("%f\n", *(*(pa + 1) + 3));
    printf("\n");

    // float* ap[2]
    printf("%llu %llu\n", (unsigned long long)ap, (unsigned long long)(ap + 1));    // 6136525888 6136525896, ap : 포인터를 담는 배열이 새로 생겨난 것
    printf("%llu\n", (unsigned long long)&ap);  // 6136525888, ap는 포인터이지만 배열로서 만들어졌기 때문에 배열의 성질을 갖는다. 배열의 이름이 배열의 대표 주소인 것 처럼
    //  ap + 1은 arr2d[1]가 담긴 포인터 변수 ap[1]의 주소를 말하는 것이다.
    printf("%llu %llu\n", (unsigned long long)arr2d[0], (unsigned long long)arr2d[1]); // 6136525904 6136525920
    printf("%llu %llu\n", (unsigned long long)ap[0], (unsigned long long)(ap[0] + 1)); // 6136525904 6136525908
    printf("%f\n", ap[0][0]);
    printf("%f\n", *ap[0]);
    printf("%f\n", **ap);
    printf("%f\n", ap[1][3]);
    printf("%f\n", *(*(ap + 1) + 3));
    printf("\n");

    
}   