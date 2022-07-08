/* 숫자 문자 판별 */

#include <stdio.h>

long get_long();    // 입력(arguement)은 필요없고 long타입의 값을 하나 받는다.

int main()
{
    // long number = get_long();   // 이렇게 함으로써 안전하게 long타입 변수 하나를 입력 받아 준다.

    long number;    // number를 while문 밖에서 출력해주기위해 밖으로 뺀다.

    while(1)
    {
        printf("Please input an integer between 1 and 77.\n");

        number = get_long();

        if (number > 1 && number < 77)
        {
            printf("Thank you.\n");
            break;
        }
        else    
            printf("Wrong input. Please try again.\n");
    }

    printf("Your input %ld is between 1 and 77. Thank you.\n", number);

    return 0;
}

long get_long() // 받고 싶은 값 : long타입 값 하나
{
    printf("Please input an integer and press enter.\n");

    long input;
    char c;

    while (scanf("%ld", &input) != 1)
    {
        printf("Your input - ");

        while ((c = getchar()) != '\n') // buffer안의 줄바꿈을 없애는 동시에 문자 출력
            putchar(c);

        printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you. \n", input);

    return input;
}