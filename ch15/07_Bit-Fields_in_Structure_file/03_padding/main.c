/* 비트필드의 패딩 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

void char_to_binary(unsigned char uc)
{
    const int bits = CHAR_BIT * sizeof(unsigned char);
    for (int i = bits -1; i >= 0; i--)
        printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)
{
    for (int i = 0; i < bytes; ++i)
        char_to_binary(data[bytes -1 -i]);
    printf("\n");
}

int main()
{
    struct {
        bool option1 : 1;
        // bool         : 0;   // 강제로 메모리를 더 달라
        // unsigned long long : 0;
        bool option2 : 1;
        unsigned long long option3 : 16;
    } bbf;
    memset((char*)& bbf, 0x00, sizeof(bbf));
    print_binary((char*)& bbf, sizeof(bbf));
    bbf.option1 = 0;
    bbf.option2 = 0;
    bbf.option3 = 0xffff;
    print_binary((char*)& bbf, sizeof(bbf));

    printf("%zu bytes\n", sizeof(bbf));     // 8bytes

    struct {
        unsigned short option1 : 8;
        unsigned short option2 : 7;
        unsigned short option3 : 1;
        // unsigned short : 0;
    } usbf;

    printf("%zu bytes\n", sizeof(usbf));    // 2bytes

    struct {
        unsigned int option1 : 1;
        unsigned int option2 : 1;
        unsigned int : 0;
    } uibf;

    printf("%zd bytes\n", sizeof(uibf));    // 4bytes

    return 0;
}
