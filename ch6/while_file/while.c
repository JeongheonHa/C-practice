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
    int num, sum = 0;
    
    printf("Enter an integer (q to quit) : ");

    while(scanf("%d", &num) == 1)   // return 값 비교
    {
        sum = sum + num;

        printf("Enter next integer (q to quit) : ");
        
    }
    printf("Sum = %d\n", sum);

    return 0;
}
