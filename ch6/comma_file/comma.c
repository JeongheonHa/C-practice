/* ,(comma) 연산자 */
// ,연산자는 우선순위가 꼴등이다.
// left to right 진행

#include <stdio.h>

int main()
{
    /* <ex1> */
    /*
    for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
        printf("%d %d\n", n, nsqr);     // printf안에 있는 ,는 연산자가 아닌 separators이다.
    */

    /* <ex2> */
    /*
    int i, j;
    i = 1;
    i++, j = i; // comma는 ;과 같은 sequnence point이다. 따라서 i++에서 ++가 실행된 후 j에 대입된다.
    printf("%d %d\n", i, j);
    */

    /* <ex3> */

    int x, y, z;
    z = x = 1, y = 2;
    printf("x=%d, y=%d, z=%d \n", x, y, z); // x=1, y=2, z=1
    z = (x = 1), (y = 2);   // 왼쪽 값을 대입
    printf("x=%d, y=%d, z=%d \n", x, y, z); // x=1, y=2, z=1
    z = ((x = 1), (y = 2)); // ( , )의 경우 오른 쪽의 값을 대입
    printf("x=%d, y=%d, z=%d \n", x, y, z); // x=1, y=2, z=2

    /* <ex4> */
    // int my_money = 123,456; // error
    int my_money = (123, 456);
    printf("%d\n", my_money);   // 456출력
    
    return 0;
    
}