/* 중첩된 루프 */
/* <ex1> */
/*
// 원하는 알파벳 부터 원하는 알파벳 까지 원하는 갯수만큼 출력
#include <stdio.h>

int main()
{
    const int num = 5;
    const int first = 'A';
    const int last = 'K';

    int r;
    int c;

    for (r = 0; r < num; ++r)   // low loop
    {
        for (c = first; c <= last; c++)
        {
            printf("%c ", c);
        }
        printf("\n");
    } 

    return 0;
}
*/

/* <ex2> */
/*
// 삼각형 형태로 만들어보기

#include <stdio.h>

int main()
{
    const int num = 10;
    const int first = 'A';
    const int last = 'K';

    int c = 0;
    int r = 0;
    
    for (r = 0; r <= num; ++r)
    {
        for (c = first; c <= first + r; ++c)
        {
            printf("%c ", c);
        }
        printf("\n");
    }

    return 0;
}
*/

/* <ex3> */
// 역삼각형으로 만들기 

#include <stdio.h>

int main()
{
    int const last = 'L';
    int const count = 12;
    
    int first = 'A';
    int c;
    int r;

    for (r = 0; r <= count; ++r)
    {
        for (c = first; c <= last; ++c)
        {
            printf("%c", c);
        }
        first += 1;
        printf("\n");
    }

    return 0;
}