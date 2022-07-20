/* 동적 할당 메모리를 배열처럼 사용하기 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        one variable (변수 하나를 사용하기위해 동적 할당을 이용) *이럴 경우 거의 없음*
    */

    // int* ptr = NULL;

    // ptr = (int*)malloc(sizeof(int) * 1);
    // if (!ptr) exit(1);

    // *ptr = 1024 * 3;
    // printf("%d\n", *ptr);

    // free(ptr);
    // ptr = NULL;

    /*
        1D array
    */
    // 포인터의 경우 배열과 유사하게 사용할 수 있다.
    // 다만, 배열의 경우 stack에 쌓이고, 동적 할당을 이용한 메모리 공간은 heap에 저장이된다. (변수 자체는 stack에 저장)

    // int* ptr = NULL;
    // int n = 3;
    // ptr = (int*)malloc(sizeof(int) * n);

    // if (!ptr) exit(1);

    // ptr[0] = 123;
    // *(ptr + 1) = 456;
    // *(ptr + 2) = 789;

    // free(ptr);
    // ptr = NULL;

    /*
        2D array
    */

    // int row = 3, col = 2;
    // int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
    // // int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);    // VLA
    
    // if (!ptr2d) exit(1);

    // for (int r = 0; r < row; r++)
    //     for (int c = 0; c < col; c++)
    //         ptr2d[r][c] = c + col * r;
    
    // for (int r = 0; r < row; r++)
    // {
    //     for (int c = 0; c < col; c++)
    //         printf("%d ", ptr2d[r][c]);
    //     printf("\n");
    // }

    /*
        Using 1D arrays as 2D arrays

        (r, c)

        index = c + col * r
    */

    int row = 3, col = 2;
    int* ptr = (int*)malloc(sizeof(int) * row * col);
    
    if (!ptr) exit(1);

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            ptr[c + col * r] = c + col * r;
    
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
            printf("%d ", *(ptr + c + col * r));
        printf("\n");
    }

    /*
        Using 1D arrays as 3D arrays
        - 2차원 배열이 2개 있는 형태

        row, col, depth

        (r, c, d)

        index = c + col * r + (col * row) * d
    */

    /* 
        Using 1D arrays as 4D arrays

        row, col, depth, height(이름 정활하지 않음)

        (r, c, d, h)

        index = c + col * r + (col * row) * d + (row * col * depth) * h
    */

    /* 함수로 만들어 사용 */
    /*
        int idx2(int c, int r)
        {
            return c + col + r;
        }

        int idx3(int c, int r, int d)
        {
            static const itn cr = col * row;
            return c + col * r + cr * d;
        }
    */
}