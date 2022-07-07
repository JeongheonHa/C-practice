/* 논리 연산자 */

#include <stdio.h>
#include <stdbool.h>
#include <iso646.h> // && -> and, || -> or, ! -> not (대신 사용가능) 

int main()
{
    // && : and
    // || : or
    // ! : not , true -> false, false -> true

    bool test1 = 3 > 2 || 4 > 7;    // bool자료형은 1,0 만 출력 (true, false)
    bool test2 = 3 > 2 && 5 > 6;
    bool test3 = !(5 > 6);

    printf("%d %d %d\n", test1, test2, test3);  // 1 0 1

    /* <ex1> */
    /*
    char const PERIOD = '.';
    char ch;
    int count = 0;

    while ((ch = getchar()) != PERIOD)
    {
        if (ch != '\n' && ch != ' ')
            count++;
    }

    printf("%d\n", count);
    */

    /* <ex2> short-circuit evaluation */
    /*
    // left -> right
    // &&, ||는 sequence point

    int temp = (1 + 2) * (3 + 4);

    printf("Before : %d\n", temp);

    if (temp == 0 && (++temp == 1024))  // &&의 경우 temp의 값이 0이 아니므로 false임을 알았기 때문에 && 뒤에는 연산하지 않는다.
                                        // ++temp 적용 X
    {

    }
    printf("After : %d\n", temp);
    */

    /* <ex3> sequence point */
    /*
    int x = 1, y = 2;
    if (x++ > 0 && x + y ==4)   // &&를 만나는 순간 x++가 실행되어 2가된 상태에서 x + y == 4를 실행하기때문에 두 조건 모두 만족
        printf("%d %d\n", x, y);  // 2 2
    */

    /* <ex4> range */
    // 두 예제 비교

    for (int i = 0; i < 100; ++i)
        if (i >= 10 && i <= 20)
            printf("%d ", i);
        
    printf("\n");

    // for (int i = 0; i < 100; ++i)   // if((10 <= i) <= 20)으로 인식
    //     if ( 10 <= i <= 20)
    //         printf("%d ", i);


    return 0;
}