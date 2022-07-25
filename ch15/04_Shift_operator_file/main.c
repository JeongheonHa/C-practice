/* 비트 단위 shift 연산자 (비트 이동 연산자) */

#include <stdio.h>

void int_binary(const int num);

int main()
{
    /*
        Bitwise shift operators
        // 항상 2^n으로 곱하거나 나누는 것은 아니지만 연산 속도가 빠르기 때문에 자주 사용된다.

        - Left shift
        number << n : multiply number by 2^n (곱하기)

        - Right shift
        number >> n : divide by 2^n (for non-negative numbers) (나누기)
    */

    // 8 bit integer cases
    // Bitwise shift operator 왼쪽에 있는 숫자의 2진수 패턴
    // 이동해서 범위를 초과한 비트는 삭제되고 빈 자리를 0으로 채운다. (NOTE : right shift에서 음수여서 앞의 비트가 1인 경우 빈 공간을 1로 채운다)

    //                                <76543210>       <76543210>     <76543210>
    printf("%hhd\n", 1 << 3);       // 00000001 ->   00000001???    -> 00001000     , 1 x 2^3을 한 것처럼 나온다. (모두가 그런 것은 아니다)
    printf("%hhd\n", 8 >> 1);       // 00001000 ->      ?00001000   -> 00000100     , 8 / 2^1을 한 것처럼 나온다. (모두가 그런 것은 아니다)

    printf("%hhd\n", -119 >> 3);    // 10001001 ->      ???10001001 -> 11110001 (-15)
    printf("%hhd\n", -119 / 8);     // (-14)
    printf("%hhu\n",  137 >> 3);    // 10001001 ->      ???10001001 -> 00010001 (17)

    printf("%hhd\n", -119 << 4);    // 10001001 ->  10001001????    -> 10010000 (-112)  , 부호 정보가 shift로 인해 사라진다.
    printf("%hhu\n",  137 << 4);     // 10001001 ->  10001001????    -> 10010000 (144)

    int a = 1;
    a <<= 3;    // 가능
    a >> 2;     // 가능

    printf("Unsigned int %u\n", 0xffffffff);    // Unsigned int 4294967295, f하나가 4bit이며 1을 의미 (32bit에서 모든 비트가 1)
    printf("Signed int %d\n", 0xffffffff);      // Signed int -1
    int_binary(0xffffffff);                     // Decimal           -1 == Binary 11111111111111111111111111111111
    printf("Right shift by 3\n");
    int_binary(  (signed)0xffffffff >> 3);      // Decimal           -1 == Binary 11111111111111111111111111111111
    int_binary((unsigned)0xffffffff >> 3);      // Decimal    536870911 == Binary 00011111111111111111111111111111

    printf("\nUnsigned int %u\n", 0x00ffffff);  // Unsigned int 16777215, 앞의 2진수 8자리가 0
    printf("Signed int %d\n", 0x00ffffff);      // Signed int 16777215
    int_binary(0x00ffffff);                     // Decimal     16777215 == Binary 00000000111111111111111111111111
    printf("Right shift by 3\n");
    int_binary(  (signed)0x00ffffff >> 3);      // Decimal      2097151 == Binary 00000000000111111111111111111111
    int_binary((unsigned)0x00ffffff >> 3);      // Decimal      2097151 == Binary 00000000000111111111111111111111

    return 0;
}

void int_binary(const int num)  // pow 대신 shift 연산자 사용 (더 효율적이며 c/c++언어 다운 프로그래밍이다)
{
    printf("Decimal %12d == Binary ", num);

    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; ++i)
    {
        const int mask = 1 << (bits -1 -i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else    
            printf("%d", 0);
    }

    printf("\n");
}

