/* for문에서 배열 사용하기 */
/*
#include <stdio.h>

#define SIZE 5

int main()
{
    int my_arr[SIZE];   // index가 5인 배열, 메모리 저장 공간 생성

    for (int i = 0; i < SIZE; ++i)  //  for문을 이용하여 index마다 메모리안에 값 지정
    {    
        my_arr[i] = i * i;
        // 1 + 2;   // dummy : 필요없는 statement, 디버깅하는 과정에서 처리과정을 확인하기 쉽기 때문에 이용한다.
    }

    for (int i = 0; i < SIZE; ++i)  // 각 index마다 지정된 값을 for문을 이용해 출력
    {
        printf("%d ", my_arr[i]);
    }

    return 0;
}
*/

/* for & array 활용 */
// 숫자 5개 입력 받고, 입력 받은 숫자들의 합을 출력

#include <stdio.h>

int main()
{
    int const NUM = 5;
    int arr[NUM];
    int sum = 0;

    printf("Enter %d numbers : ", NUM);

    for (int i = 0; i < NUM - 1; ++i)
        scanf("%d\n", &arr[i]);

    for (int i = 0; i < NUM - 1; ++i)
        sum += arr[i] ;

    printf("Sum = %d\n", sum);
    
    return 0;
}