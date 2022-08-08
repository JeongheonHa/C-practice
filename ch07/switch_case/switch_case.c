/* switch & case */
// char, int같은 정수형만 switch, case 사용 가능

#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    while (( c = getchar()) != '.')
    {
        printf("You love ");

        switch (tolower(c))  // 값에 대해 살펴보고 싶은 변수를 넣는다. (숫자도 가능하지만 변수말고 상수를 넣는 것은 고정이 되기 때문에 큰 의미 없다.)
        {
        case 'a':
        // case 'A': , 'a'다음 break가 없기 때문에 'A'도 적용 
            printf("apple");
            break;
        case 'b':
            printf("baseball");
            break;
        case 'c':
            printf("cake");
            break;
        default :   // 아무것도 입력하지 않았을 때의 경우
            printf("nothing");

        }

        printf(".\n");

        while (getchar() != '\n')   // 줄바꿈이 나올때까지 case 후에 나온 문자 모두 무시
            continue;
    }

    return 0;
}