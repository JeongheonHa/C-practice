/* 숫자 문자 판별 */
/*
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
*/

/* 메뉴 만들기 */
// <1>
/*
#include <stdio.h>

int main()
{
    int i;
    int count = 0;
    char ch;

    while (1)
    {
        printf("Enter the letter of your choice: \n");
        printf("a. avengers     b. beep\n");
        printf("c. count        q. quit\n");

        if ((ch = getchar()) == 'a')
        {
            printf("avengers assemlbe!\n");
            while (getchar() != '\n')
                continue;
        }
        else if (ch == 'b')
        {
            printf("\a\n");
            while (getchar() != '\n')
                continue;
        }
        else if (ch == 'c')
        {
            printf("Enter an integer :");
            scanf("%d", &i);
            while (count < i)
            {
                ++count;
                printf("%d\n", count);
            }
            while (getchar() != '\n')
                continue;
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }

        if (ch == 'q')
        {
            break;
        }
        
    }

    return 0;
}
*/

// <2> 다른 풀이

#include <stdio.h>
#include <stdlib.h>

char get_choice();
char get_first_char();
int get_integer();
void count();

int main()
{
    int user_choice;

    while ((user_choice = get_choice()) != 'q')
    {
        switch (user_choice)
        {
        case 'a':
            printf("Avengers assemble!\n");
            break;
        case 'b':
            putchar('\a');
            break;
        case 'c':
            count();
            break;
        default :
            printf("Error with %d\n", user_choice);
            exit(1);
            break;
        }
    }
    return 0;
}

void count()
{
    int n, i;

    printf("Enter an integer:\n");
    n = get_integer();
    for (i = 1; i <= n; ++i)
        printf("%d\n", i);
    while (getchar() != '\n')
        continue;
}

char get_choice()
{
    int user_input;

    printf("Enter the letter of your choice:\n ");
    printf("a. avengers\tb. beep\n");
    printf("c. count\tq. quit\n");

    user_input = get_first_char();

    while ((user_input < 'a' || user_input > 'c') && user_input !='q')
    {
        printf("Please try again.\n");
        user_input = get_first_char();
    }

    return user_input;
}

char get_first_char()
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

int get_integer()
{
    int input;
    char c;

    while (scanf("%d", &input) != 1)
    {
        while ((c = getchar()) != '\n')
            putchar(c);
        printf(" is not an integer.\nPlease try again.");
    }

    return input;
}
        
