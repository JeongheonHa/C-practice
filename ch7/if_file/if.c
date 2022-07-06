/* if문 */

#include <stdio.h>

int main()
{
    int number ;

    printf("Input a positive integer : ");
    scanf("%d", &number);

    if (number % 2 ==0)
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}