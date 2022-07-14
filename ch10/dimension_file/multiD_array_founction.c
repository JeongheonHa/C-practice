/* 다차원 배열을 함수에게 전달해주는 방법 */

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d_1(int ar[ROWS][COLS]);
int sum2d_2(int ar[][COLS], int row);   // 다차원의 경우 첫번째 []만 생략 가능, []가 생략가능한 이유 : 배열의 이름은 첫 원소의 주소이기 때문에 포인터로 변환된다.
// int sum2d_2(int [][CLOS], int row);  // 이름 생략 가능
// int sum2d_2(int (*ar)[COLS], int row)    // COLS 개수만큼의 원소를 갖는 배열의 포인터 하나 
int sum2d_3(int* ar, int row, int col); // 실질적인 다차원 배열의 프로토타입 선언
// int sum2d_3(int*, int, int); 변수 이름 생략 가능
int sun2d_4(int row, int col, int ar[row][col]);

int main()
{
    int data[ROWS][COLS] = {
                                {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 0, 1, 2}
                                                };
    printf("%d\n", data[2][3]);

    int* ptr = &data[0][0];
    printf("Sum of all elements = %d\n", sum2d_1(data));
    printf("%d\n", *(ptr + 3 + COLS * 2));  // 1차원 array를 2차원 array처럼 접근

    printf("Sim of all elements = %d\n", sum2d_1(data));
    printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
    printf("Sum of all elements = %d\n", sum2d_3(data[0][0], ROWS, COLS));

    /* Variable - Length Arrays (VLAs : 가변 길이 배열) */
    // 변수로 길이를 정할 수 있는 배열

    int n;

    printf("Input array length : ");
    scanf("%d", &n);
    
    float my_arr[n];    // 길이 선언후 길이를 바꿀 수 없다.

    for (int i = 0; i < n; ++i)
        my_arr[i] = (float)i;
        
    for (int i = 0; i < n; ++i)
        printf("%f\n", my_arr[i]);

    int data[ROWS][COLS] = {
                                {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 0, 1, 2}
                                                };
    printf("%d\n", sum2d_4(ROWS, COLS, data));

    return 0;
}

int sum2d_1(int ar[ROWS][COLS])
{
    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
    return tot;
}

int sum2d_2(int ar[][COLS], int row)
{
    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
    return tot;
}

int sum2d_3(int* ar, int row, int col)
{
    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            tot += *(ar + c + col * r); // ar[c + col * r]
    return tot;
}

int sum2d_4(int row, int col, int ar[row][col]) // 매크로를 덜 사용하기 때문에 간결하며 정리가 된 느낌이다, (매개변수 만으로 함수의 내용을 정리)
{
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            tot += ar[r][c];
    return tot;
}