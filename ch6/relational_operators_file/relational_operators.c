/* 관계 연산자 */
// <    왼쪽에 있는 것이 작은가?
// <=   작거나 같은가?
// ==   같은가?
// >=   크거나 같은가?
// >    큰가?
// !=   다른가?

#include <stdio.h>
#include <math.h>   // fabs를 사용할 수 있다. fabs : 절대값을 표현

int main()
{   
    /* <ex1> */
    /*
    int n = 0;
    while (n++ < 5)
        printf("%d", n);
    */

    /* <ex2> */
    /*
    char c = 'A';
    while (c != 'Z')
        printf("%c", c++);
    */

    /* <ex3> */
    const double PI = 3.141592;     //#define으로 정의할 수 있지만 현재에는 const를 사용하는 것을 권장
    double guess = 0.0;

    printf("Input pi : ");
    scanf("%lf", &guess);

    // while (guess != PI)     // != : 정확히 일치해야한다. (정수 비교와 달리 실수끼리 비교를 할때는 직접적으로 비교를 못하는 경우가 빈번히 발생)
    while (fabs(guess - PI) > 0.01)     // 절대값을 이용해 입력값과 const값의 오차범위를 표현
    {
        printf("Fool! Try again.\n");
        scanf("%lf", &guess);
    }

    printf("Good!\n");
}