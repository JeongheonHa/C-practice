/* loop 도우미 continue & break */

#include <stdio.h>

int main()
{
    /* continue */
    /*
    for (int i =0; i < 10; ++i)
    {
        if (i == 5)
            continue;   // continue 뒷부분 실행 X -> ++i 

        printf("%d", i);    // 012346789
    }
    */

    /* break */

    /* <ex1> */
    /*
    for (int i =0; i < 10; ++i)
    {
        if (i == 5)
            break;  // 루프에서 나와버린다.

        printf("%d", i);    // 01234
    }
    */

    /* <ex2> */
    /*
    // 무한 루프를 만들고 그 안에서 break로 해결, *선호*
    while(1)
    {
        char c = getchar();

        if (c == '.')
            break;

        putchar(c);
    }
    */

    /* <ex3> */
    // 다중 루프안에서 break
    // 자신을 포함한 첫번째 루프를 빠져나온다.

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)
                break;
            
            printf("(%d %d)", i, j);
        }

        printf("\n");
    }


    /* while and continue */

    int count = 0;
    while (count < 5)
    {
        int c = getchar();
        if (c == 'a')   // 'a 무시
            continue;
        putchar(c); // 문자열에서 'a' 무시하고 5개 문자 출력
        count++;
    }

    /* continue as a placeholder */
    
    while (getchar() != '\n')
        continue;   // placeholder : null statement 대신에 아무 기능도 하지않지만 이곳에 무언가 존재한다는 것을 표시하고 싶을 때 사용


    return 0;
}