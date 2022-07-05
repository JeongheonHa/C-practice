/* for문 */
// 반복문에는 크게 indefinite loop 와 counting loop로 나뉜다.
// counting loop의 특징
// 1. counter initialization
// 2. counter check
// 3. counter change

#include <stdio.h>

int main()
{
    /* <ex1> */
    // 기존의 while문을 이용할 경우
    /*
    int i;

    i = 1;

    while (i <= 10)
    {
        printf("%d", i);
        i++;
    }
    */

    /* <ex2> */
    // while문을 for문으로 만들 경우
    int i;

    for (i = 1; i <= 10; i++)   // for (int i = 1; ...)로 int i;변수선언을 for문 내에서 할 수 있다.
    {
        printf("%d", i);    // 간단하게 나올경우 {} 생략 가능
    }
    // 과정 : int i로 변수 선언 -> i = 1로 초기화 -> i 와 10비교 후 {}안으로 진입 후 출력 -> i++로 i증가
    //       -> 증가된 i와 10비교 -> ... -> i와 10비교 후 조건에 맞지않을 경우 루프 탈출
    return 0;
}
