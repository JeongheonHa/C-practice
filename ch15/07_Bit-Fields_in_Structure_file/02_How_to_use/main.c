/* 비트필드의 사용방법 */

#include <stdio.h>
#include <limits.h> // CHAR_BIT
#include <stdbool.h>

void char_to_binary(unsigned char uc)
{
    const int bits = CHAR_BIT * sizeof(unsigned char);
    for (int i = bits -1; i >= 0; i--)
        printf("%d", (uc >> i)& 1);
}

void print_binary(char* data, int bytes)
{
    for (int i = 0; i < bytes; ++i)
        char_to_binary(data[bytes -1 -i]);
    printf("\n");
}

int main()
{
    struct items {
    bool has_sword    : 1;  
    bool has_shield   : 1; 
    bool has_potion   : 1;
    bool has_guntlet  : 1;
    bool has_hammer   : 1;
    bool has_key      : 1;
    bool has_ring     : 1;
    bool has_amulet   : 1;      // 1 비트짜리 has_amulet을 bool처럼 해석해라
} items_flag;

items_flag.has_sword    = 1;    // 1 대신 true도 가능 (bool이기때문에)
items_flag.has_shield   = 1;    // flags = flags | MASK_SHIELD;
items_flag.has_potion   = 0;
items_flag.has_guntlet  = 1;
items_flag.has_hammer   = 0;
items_flag.has_key      = 0;
items_flag.has_ring     = 1;
items_flag.has_amulet   = true;

printf("Size = %zd\n", sizeof(items_flag));             // Size = 1

print_binary((char*)&items_flag, sizeof(items_flag));   // 11001011

if (items_flag.has_key == 1)
    printf(">> You can enter.\n");

union {
    struct items  bf;   // 두 멤버의 메모리 사이즈는 동일
    unsigned char uc;
} uni_flag;

uni_flag.uc = 0;
uni_flag.bf.has_amulet = true;
uni_flag.uc |= (1 << 5);

print_binary((char*)& uni_flag, sizeof(uni_flag));      // 10100000
uni_flag.bf.has_key = false;
print_binary((char*)& uni_flag, sizeof(uni_flag));      // 10000000

// 비트 필드를 사용할 수 도 있고 비트 단위 연산자를 사용할 수 도 있다.

// <ex>
// 모든 파일에 공통적으로 들어가는 정보는 작을 수록 좋다. (비트 필드를 이용)
struct file_time {
    unsigned int seconds : 5;   // 2^5 = 32, (0 ~ 29) 30*2 seconds (2초 단위로 저장)
    unsigned int minutes : 6;   // 2^6 = 64, (0 ~ 59) 60 minutes
    unsigned int year    : 7;   // 2^5 = 32, (0 ~ 23) 24 hours
};

struct file_date {
    unsigned int day     : 5;   // 2^5 = 32, 1 ~ 31 , 컴파일러에게 day를 unsigned int처럼 해석을 해달라고 요청 (하지만 실제로 사용하는 메모리는 5bit)
    unsigned int month   : 4;   // 2^4 = 16, 1 ~ 12
    unsigned int year    : 7;   // 2^7 = 128, 1980 ~
} fd;

/* 1988 12 28 */
fd.day = 28;
// fd.day = 32; // error, overflow
fd.month = 12;
fd.year = 8;

printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);
// scanf("%d", &fd.day); // Wrong, 비트 필드는 비트 단위로 메모리를 사용하기 때문에 scanf와 같이 주소를 넘겨주는 경우에는 주소의 최소 단위인 1byte를
                         // 넘겨줄 수 없기 때문에 compile할때 막아 놓았다.

return 0;
}