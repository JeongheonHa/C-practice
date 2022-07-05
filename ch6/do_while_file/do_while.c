/* 탈출조건 루프 do while */

#include <stdio.h>

int main()
{
    const int passward = 1234;
    int i = 0;

    /*
    printf("Enter your passward : ");
    scanf("%d", &i);
    
    for (; i != passward;)
    {
        printf("Enter your passward : ");
        scanf("%d", &i);
    }
    */

    // do while 활용해보기
    // while을 실행하기 전 1번 실행 후 while문 실행
    do
    {
        printf("Enter your passward : ");
        scanf("%d", &i);
    } 
    while (i != passward);
    

    printf("Good\n");

    return 0;
}