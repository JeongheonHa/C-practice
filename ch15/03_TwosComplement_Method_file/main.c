/* 2의 보수 표현법 */

#include <stdio.h>
#include <math.h>

void print_binary(const char num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;

    for (size_t i = 0; i < bits; ++i)
    {
        const char mask = (char)pow((double)2, (double)(bits -1 -i));   // signed 인지 unsigned인지 mask에게 중요하지 않다.

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    printf("\n");
}

int main()
{
    /*
    <Signed Integers>
    // 부호가 있는 정수를 계산할 때 2의 보수 표현법을 사용한다.
    
    // <1>
    - Sign-magnitude representation
    00000001 is 1 and 10000001 is -1
    00000000 is +0, 10000000 is -0
    Two zeros +0 -0, from -127 to +127

    // <2>
    - One's complement method
    To reverse the sign, invert each bit
    00000001 is 1 and 11111110 is -1
    11111111 is -0
    from -127 to +127

    // <3> ***
    - Two's complement method (commonly used in most systems)
    To reverse the sign, invert each bit and add 1 (각각의 비트를 0 -> 1, 1 -> 0으로 바꾸고 1을 더해준다.)
    from -128 to +127
    */

    print_binary(127);      // 01111111
    print_binary(-127);     // 10000001
    print_binary(~127 + 1); // 10000001

    print_binary(12);       // 00001100
    print_binary(-12);      // 11110100
    print_binary(~12 + 1);  // 11110100

    print_binary(7);        // 00000111
    print_binary(-7);       // 11111001
    print_binary(~-7 + 1);  // 00000111

    return 0;

}