/* _Bool */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    /* <ex1> */

    int i;
    _Bool boolean_true = (2 > 1);   // _Bool형은 내부적으로 정수형으로 처리
    _Bool boolean_false = (1 > 2) ;

    printf("True is %d\n", boolean_true);
    printf("False is %d\n", boolean_false);

    /* 3항 연산자 */
    // _Bool은 정수형으로 처리하기 때문에 1, 0으로 출력 -> 3항 연산자 -> true, false로 출력
    // boolean_true(expression)가 사실이면 true , 거짓이면 false 출력
    printf(boolean_true ? "true" : "false");    
    printf("\n");
    printf(boolean_false ? "true" : "false");

    /* <ex2> */
    // #include <stdbool.h> 사용

    bool bt = true;
    bool bf = false;

    printf("\n");
    printf("True is %d\n", bt);
    printf("False is %d\n", bf);

    return 0;
}
