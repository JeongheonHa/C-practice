#include <stdio.h>

int main()
{
    float won = 0.0f;  // 실수를 표현할때는 float을 사용
    float dollar = 0.0f;

    printf("Input Won\n");
    scanf("%f", &won);  // 형식지정자 d -> f사용

    dollar = won * 0.00089f;

    printf("Dollar = %f\n", dollar);

    return 0;
}