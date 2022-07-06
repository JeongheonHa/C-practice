/* scope */
// 제곱근 출력
#include <stdio.h>

int compute_pow(int base, int exp); // prototype으로 분리, 함수 정의를 할때 main보다 위에 있어야하며 함수 정의가 많아질 경우
                                    // 보기 쉽게하기위해 prototype으로 분리한다.
                                    // compute_pow라는 함수가 아래 어디에 있다는 것을 의미하며 main함수에서 쓸 경우 link해준다.
int main()
{
    int base, exp, result;
    while(scanf("%d %d", &base, &exp) ==  2)    // scanf의 출력값은 문자의 개수임을 이용, 입력한 것이 숫자가 아닐 때까지 반복
    {
    // result = 1;
    // for (i = 0; i < exp; ++i)
    //    result *= base;

    result = compute_pow(base, exp);    //statement가 많아질 경우 보기 쉽게 정리하기 위해 따로 compute_pew함수를 정의

    printf("Result  = %d\n", result);
    }

    return 0;
}

int compute_pow(int base, int exp)  // int base, int exp라는 2개의 변수를 받는다.
{
    int i, result;  // int i, result라는 변수를 사용하여
    result = 1;
    for (i = 0; i < exp; ++i)   // base, exp를 계산하고
        result *= base;

    return result;  // 계산 결과(result)를 돌려보낸다. (compute_pew(base, exp)로 돌려보내서 main함수내의 result에 저장)
                    // *주의* main 함수내의 result와 다른 result이다.
}