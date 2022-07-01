#include <stdio.h>
#include <limits.h>  // 각각의 자료형이 가질 수 있는 가장큰값과 작은값을 알려준다.
#include <stdlib.h>
int main()
{
    /* 2진수 표현방법 */
    // unsigned int i = 0b11111111111111111111111111111111; (32개)

    /* 메모리 사이즈 알아보기 */
    // unsigned int i = 0;

    //  printf("%u\n", sizeof(unsigned int));   // 4byte, 32bit
    //  printf("%u\n", sizeof(i));  //4byte, 32bit

    /* 최대값 최소값 알아보기 */
    // unsigned int u_max = UINT_MAX;
    // unsigned int u_min = 0;
    // signed int i_max = INT_MAX;
    // signed int i_min = INT_MIN;

    // printf("max of uint = %u\n", u_max);    // 4294967295
    // printf("min of uint = %u\n", u_min);    // 0
    // printf("max of int = %u\n", i_max);     // 2147483647
    // printf("max of int = %u\n", i_min);     // 2147483648

    /* overflow */
    unsigned int u_max = UINT_MAX + 1;
    
    // i to binary representation
    char buffer[33];
    _itoa(u_max, buffer, 2);
    
    // print decimal and binary
    printf("decimal : %u\n", u_max);
    printf("binary : %s\n", buffer);

    // 32bit에서 1을 더해 overflow를 하면 최소값인 0으로 돌아간다. ex) 4bit의 경우 1111 + 1 -> 10000 앞의 1을 제외한 0 4개만 출력
    // 최소값에서 - 1을 하면 변수의 사이즈의 최대값으로 돌아간다.

    return 0;
}