/* 최대 최소 평균 구하기 */

#include <stdio.h>
#include <float.h>  // FLT_MAX사용 가능

int main()
{
    float max = -FLT_MAX;   // 초기화 시킬때 float의 메모리의 가장 작은 값으로 초기화하여 input으로 무엇을 입력해도 max보다 크도록 한다.
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;  // 입력 횟수 

    while (scanf("%f", &input) == 1)    // 개수가 1개일 경우 while문 실행
    {
        if (input < 0.0f || input > 100.0f) continue;   // 0 < input < 100 범위 밖은 무시

        max = (input > max) ? input : max;  // *중요*
        min = (input < min) ? input : min;
        sum += input;

        n++;
    }

    if (n > 0)
        printf("min = %f, max = %f, avg = %f\n", min, max, sum / n);
    else
        printf("No input\n");

    return 0;
}