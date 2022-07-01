/* 2진수, 8진수, 16진수 알아보기 */
#include <stdio.h>

int main()
{
    unsigned int decimal = 4294967295;
    unsigned int binary = 0b11111111111111111111111111111111;   // 0b 2진수
    unsigned int oct = 037777777777;    // 0 8진수
    unsigned int hex = 0xffffffff;      // 0x 16진수

    /* %u를 이용해 각각의 변수를 10진수로 출력 */
    printf("%u\n", decimal);    // 4294967295
    printf("%u\n", binary);     // 4294967295
    printf("%u\n", oct);    // 4294967295
    printf("%u\n", hex);    // 4294967295

    /* 8진수, 16진수로 출력해보기 */
    printf("%o %x %#o %#x %#X\n", decimal, decimal, decimal, decimal, decimal);
    // 37777777777 ffffffff 037777777777 0xffffffff 0XFFFFFFFF
    // # : 8진수, 16진수임을 표현하고싶을 때 사용 
    
    return 0;
}