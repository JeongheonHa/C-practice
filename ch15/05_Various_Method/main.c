/* 비트 단위 연산자의 다양한 사용법 */
// 아이템을 가지고있을 경우와 없을 경우를 나타내는 예제

#include <stdio.h>
#include <math.h>
//                   Shift         Decimal  Binary      Hex     Octet
#define MASK_SWORD   (1 << 0)   // 2^0      00000001    0x01    01
#define MASK_SHIELD  (1 << 1)   // 2^1      00000010    0x02    02
#define MASK_POTION  (1 << 2)   // 2^2      00000100    0x04    03
#define MASK_GUNTLET (1 << 3)   // 2^3      00001000    0x08    010
#define MASK_HAMMER  (1 << 4)   // 2^4      00010000    0x10    020
#define MASK_KEY     (1 << 5)   // 2^5      00100000    0x20    040
#define MASK_RING    (1 << 6)   // 2^6      01000000    0x40    0100
#define MASK_AMULET  (1 << 7)   // 2^7      10000000    0x80    0200
// Shift 와 Hex를 많이 사용함

void char_binary(const char num);
void int_binary(const int num);

/*
    mask : 보고싶은 것만 보겠다는 의미

    flag            01011010 (flag : 정보를 표현하는 변수)
    mask            00000011 (1이 있는 곳만 보갰다)
    mask & flag ==  00000010 (mask로 1만 보고싶은 것 중에 flag가 1인 것)
*/

int main()
{
    char flags = 0;                 // MASK flags (아이템이 아무것도 없는 상태)
    char_binary(flags);             // Decimal   0     == Binary 00000000

    printf("\nTurning Bits On (Setting Bits)\n");

    flags = flags | MASK_SWORD;     // flags |= MASK_SWORD; 도 가능 (SWORD를 획득했을 경우 MASK_SWORD flag를 켜준다.)
    char_binary(flags);             // Decimal   1     == Binary 00000001
    flags |= MASK_AMULET;           // MASK_AMULET에 할당하는 비트를 켜준다.
    char_binary(flags);             // Decimal -127    == Binary 10000001

    printf("\nTurning Bits Off (Clearning Bits)\n");

    flags = flags | MASK_POTION;
    char_binary(flags);             // Decimal -123    == Binary 10000101
    flags = flags & ~MASK_POTION;   // 비트를 꺼준다.
    char_binary(flags);             // Decimal -127    == Binary 10000001

    printf("\nToggling Bits\n");
    // 아이텀을 누르면 장착을 했다가 다시 한번 누르면 해제하는 경우 (toggling)
    flags = flags ^ MASK_HAMMER;
    char_binary(flags);             // Decimal -111    == Binary 10010001

    flags = flags ^ MASK_HAMMER;
    char_binary(flags);             // Decimal -127    == Binary 10000001

    flags = flags ^ MASK_HAMMER;
    char_binary(flags);             // Decimal -111    == Binary 10010001

    printf("\nChecking the value of a Bit\n");

    if ((flags & MASK_KEY) == MASK_KEY) // MASK_KEY 비트가 있는지 없는지 확인
        printf(">> You can enter.\n");
    else
        printf(">> You can not enter.\n");

    flags |= MASK_KEY;  // obtained a key (bit on)

    if ((flags & MASK_KEY) == MASK_KEY)
        printf(">> You can enter.\n");
    else
        printf(">> You can not enter.\n");

    printf("\nTrimming\n");

    int int_flag = 0xffffffff;
    // 11111111111111111111111111111111
    int_binary(int_flag);           // Decimal           -1 == Binary 11111111111111111111111111111111
    int_flag &= 0xff;
    // Trim by 11111111
    int_binary(int_flag);           // Decimal          255 == Binary 00000000000000000000000011111111

    return 0;
}

void char_binary(const char num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; ++i)
    {
        const char mask = 1 << (bits -1 -i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }

    printf("\n");
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