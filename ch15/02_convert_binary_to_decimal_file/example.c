/* &를 이용하는 십진수 -> 이진수 문제 */

#include <stdio.h>
#include <math.h>   // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
    unsigned char i = to_decimal("01000110");
    unsigned char mask = to_decimal("00000101");

    print_binary(i);
    print_binary(mask);
    print_binary(i & mask);

    return 0;
}

void print_binary(const unsigned char num)
{
    printf("Decimal %3d \t== Binary ", num);

    const size_t bits = sizeof(num) * 8;

    // <1> size_t i = 0의 경우
    for (size_t i = 0; i < bits; ++i)
    {
        const unsigned char mask = 
            (unsigned char)pow((double)2, (double)(bits -1 -i));    // 2의 7번째 자리를 먼저
            // unsigned char mask = pow(2, (bits -1 -i));   // casting을 하지 않아도 된다. pow는 인자를 받을 때 double타입으로 받는다.

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }

}

// <2> int i = bits - 1의 경우
//// for (size_t i = bits - 1; i >= 0; --i)   // size_t error, size_t의 자료형은 unsigned int이기 때문에 0에서 -1을 하면 최대값으로 돌아가버린다.
                                            // NOTE : --i를 사용할때는 unsigned int를 사용하면 안된다. (무한 루프)
// for (int i = bits - 1; i >= 0; --i)
//     {
//         const unsigned char mask = 
//             (unsigned char)pow((double)2, (double)i);   
//             // unsigned char mask = pow(2, (bits -1 -i));   

//         if ((num & mask) == mask)
//             printf("%d", 1);
//         else
//             printf("%d", 0);

unsigned char to_decimal(const char bi[])
{
    const size_t bits = strlen(bi);
    unsigned char sum = 0;
    for (size_t i = 0; i < bits; ++i)
    {
        if (bi[i] == '1')
            sum += (int)pow(2, bits - 1 - i);
        else if (bi[i] != '0') {
            printf("Wrong character : %c", bi[i]);
            exit(1);
        }
    }

    return sum;
}