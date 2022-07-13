/* 포인터의 배열과 2차원 배열 */

#include <stdio.h>

int main()
{
    /* Two of 1D arrays */

    // int arr0[3] = {1, 2, 3};
    // int arr1[3] = {4, 5, 6};

    // int* parr[2] = {arr0, arr1};    // 포인터가 담길 수 있는 메모리 공간을 2개 확보한 배열 (int*로 이해하면 편하다)

    // for (int j = 0; j < 2; ++j)
    // {
    //     for (int i = 0; i < 3; ++i)
    //         printf("%d(==%d, %d) ", parr[j][i], *(parr[j]+ i), *(*(parr + j) + i)); // parr[j][i] : 2중 배열인 것 처럼 사용 가능, 3개다 같은 뜻
    //     printf("\n");
    // }
    // printf("\n");

    /* 2D arrays are arrays of 1D arrays */

    // int arr[2][3] = { {1, 2, 3}, {4, 5, 6}};

    // int *parr0 = arr[0];    
    // int *parr1 = arr[1];

    // for (int i = 0; i < 3; ++i)
    //     printf("%d ", parr0[i]);    // 1 2 3
    // printf("\n");

    // for (int i = 0; i < 3; ++i)
    //     printf("%d ", parr1[i]);    // 4 5 6
    // printf("\n");

    /* arrays of pointers works like a 2D array */

    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // int* parr[2] = { arr[0], arr[1] };   // 아래와 같은 표현
    int* parr[2];
    parr[0] = arr[0];
    parr[1] = arr[1];

    for (int j = 0; j < 2; ++j)
    {
        for (int i = 0; i < 3; ++i)
            printf("%d %d %d %d\n", 
                arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i)); // 4개 다 같은 의미
        printf("\n");
    }
    printf("\n");

    /* 주의 사항 */
    // parr[0] and parr[1] do not point valid memory by default
    // &parr[0] != &arr[0]
    // &parr[0] != parr[0] but &arr[0] == arr[0]

    /* 포인터의 배열과 배열의 차이 */

    printf("%p\n",&parr[0]);    // 포인터 배열 자체의 주소, (이것만 빼고 나머지 printf 같은 값)
    printf("%p\n",parr[0]);     // parr[0]가 기리키는 arr[0]의 주소

    printf("%p\n",arr);     // arr : 주소의 이름, 주소를 저장하는 별도의 메모리 공간을 갖지 않는다, 단지 아래와 같이 사용할 수 있도록 c문법에서 알려준다.
                            // vs parr : int* parr[2]을 예로 들어 arr배열의 주소를 저장할 수 있는 4바이트 공간 2개 중 첫번째 주소를 가리킨다.
    printf("%p\n",&arr[0]);

    printf("%p\n",arr[0]);
    printf("%p\n",&arr[0][0]);

    /* array of string of diverse lengths example */

    char* name[] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie"}; // name : char타입에 대한 포인터의 배열
    // name이라는 포인터의 배열에 4개의 원소가 담겨있다. (4개의 원소 : 각 문자열의 첫번째 주소)

    const int n = sizeof(name) / sizeof(char*); // n = 4

    for (int i = 0; i < n; ++i)
        printf("%s at %llu\n", name[i], (unsigned long long)name[i]);   // 글자 수 만큼 메모리 사이즈가 차이난다. (64 bit에서는 long long 사용)
    printf("\n");

    // <다른 풀이> 
    char aname[][15] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar"};

    const int an = sizeof(aname) / sizeof(char[15]);

    for (int i = 0; i < an; ++i)
        printf("%s at %llu\n", aname[i], (unsigned long long)&aname[i]);   // 배열의 길이 15만큼 메모리 사이즈 증가.
    printf("\n");

    return 0;
}
