/* 소수 */
// 소수 표현해보기

#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned num, div;
    bool isPrime;    // flag같은 경우 보통 int를 많이 사용한다. 

    scanf("%u", &num);

    isPrime = true; // true로 지정

    for (div = 2; (div * div) <= num; ++div) // 계산과정에서 목이 0인경우가 나오면 false로 바뀜.
    {
        if (num % div == 0)
        {
            isPrime = false;

            if (num == div * div)
                printf("%u is divisible by %u\n", num, div);
            else
                printf("%u is divisible by %u and %u\n", num, div, num/div);
        }
    }
    
    if (isPrime)    // isPrime이 true면 출력, 몫에 0이나오지않아 isprime이 기존의 true를 대입
        printf("%u is a prime number.\n", num);
    else    // 몫에 0이나와 isprime이 false로 바뀌어서 대입
        printf("%u is not prime number.\n", num);
    
    return 0;
}