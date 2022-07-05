/* while */
// scanf의 return값을 이용한 예제

#include <stdio.h>

int main()
{   
    /*
    int num, sum;
    int status;

    printf("Enter an integer (q to quit) : ");
    status = scanf("%d", &num);

    while(status == 1)
    {
        sum = sum + num;

        printf("Enter next integer (q to quit) : ");
        status = scanf("%d", &num);
        
    }
    printf("Sum = %d\n", sum);

    return 0;
    */

    /* 간결하게 만들기 */
    /*
    int num, sum = 0;
    
    printf("Enter an integer (q to quit) : ");

    while(scanf("%d", &num) == 1)   // return 값 비교
    {
        sum = sum + num;

        printf("Enter next integer (q to quit) : ");
        
    }
    printf("Sum = %d\n", sum);

    return 0;
    */

    /* 진입조건 루프 */
    // while의 기본 문법
    // while (expression)   // expression이 0이면 false 수행 X, 0이 아닌 값이면 수행
    //    statement
    
    int i;

    /* <ex1> */
    /*
    i = 1;
    while (i < 5)   // infinite loop
        printf("Hi!\n");    // iteration (반복)
    */

    /* <ex2> */
    /*
    i = 1;
    while (--i < 5)     // 점점 작아지는 방향으로 가기 때문에 무한 루프
        printf("Hi!\n)");
    */

    /* <ex3> */
    /*
    i = 1;
    while (i < 5)
    {
        printf("i before = %d\n", i);
        i++;
        printf("i after = %d\n", i);
    }
    */

    /* common mistakes */
    /* <ex1> */
    /*
    i = 0;
    while (i < 3)
        printf("%i\n", i);
        i++;    // indenting : {}를 붙이는 것
    */

    /* <ex2> */
    /*
    i = 0;
    while (i++ < 3);    // null statement, printf를 while문과 독립된 함수로 인식

    printf("%i\n", i);
    */

    /* <ex3> */

    while (scanf("%d", &i) == 1)    // 실행은 가능하지만 보기 좋지않기 때문에 사용 X
        ;   // null statement
    // do something

    return 0;
}
