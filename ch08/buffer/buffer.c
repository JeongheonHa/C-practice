/* buffer */

/* <ex1> */
/*
// 입력한 문자들 일단 버퍼에 저장. 버퍼에 저장된 문자 하나씩 변수 c에 넣고 c로 if를 돌면서 비교. getchar에서 입력후 입력된 엔터가 버퍼에 저장. \n (엔터)가 else로 들어감.
// c가 돌고나서 엔터가 else에 들어가기 때문에 c가 한바퀴 돌기 전에 c다음에 오는 문자가 어떤 것이든 제거하는 while문 사용. 따라서 뒤에 문자가 어떤 것이든 첫번째 문자만 비교

#include <stdio.h>

int main()
{
    int count = 0;

    while (1)
    {
        printf("Current count is %d, Continue \? (y/n)\n", count);

        int c = getchar();  // 입력된 문자 변수 c에 저장

        if (c == 'n')   // c가 n이라면 break, getchar의 첫번째 문자에 대해 비교
        {
            break;  // while문 탈출
        }
        else if (c == 'y')  // c가 y라면 count++
        {
            count++;
        }
        else            // 둘 다 아니면 please input y or n 출력
        {
            printf("Please input y or n");
        }

        while (getchar() != '\n')    // getchar의 모든 문자에 대해 비교, \n이 입력 뱓은 문자가 아니라면 뒷 부분 생략
            continue;
    }

    return 0;
}
*/

/* <ex2> */

#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
    char c;
    int rows, cols;

    // <1>
    /*
    while (1)
    {
        scanf("%c %d %d", &c, &rows, &cols);    // scanf는 줄바꿈을 시행한 후 버퍼에 남겨둔다.
        while (getchar() != '\n') continue;     // scanf로 인해 생긴 버퍼안에 있는 줄바꿈을 없앤다.
        display(c, rows, cols); // 선언된 함수에 넣을 변수를 지정, cr이라는 변수에 c를 대입
        if ( c == '\n')
            break;
    }
    */

    // <2> *선호*

    printf("Input one character and two integers : \n");
        while ((c = getchar()) != '\n')
        {
            scanf("%d %d", &rows, &cols);
            while (getchar() != '\n') continue; 

            display(c, rows, cols);
            printf("Input another character and two integers : \n");
        }
    
    return 0;
}

void display (char cr, int lines, int width)    // 이 함수 내에서 사용하는 cr은 입력받은 c이다.
{
    int row, col;

    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');
    }
}
