/* 배열과 런타임 에러 */

#include <stdio.h>

int main()
{   
    /* <ex1> */
    /*
    int const DAYS = 365;

    char my_chars[] = "Hello, World!";

    int daily_temperature[DAYS];
    double stock_prices_history[DAYS];

    printf("%zd\n", sizeof(stock_prices_history));  // double의 메모리 사이즈 : 8byte, [DAYS] : 365개의 데이터 매모리 공간(double) 확보
    printf("%zd\n", sizeof(double) * DAYS);
    printf("%zd\n", sizeof(stock_prices_history[0]));   // 8
    */

    /* <ex2> */

    int my_numbers[5];

    my_numbers[0] = 1;  // my_numbers[0] : 첫 주소, index : []안의 숫자, offsets : 0에서부터 얼만큼 떨어져 있는가
    my_numbers[1] = 6;  
    my_numbers[2] = 4;
    my_numbers[3] = 2;
    my_numbers[4] = 1024;

    scanf("%d", my_numbers);    // 변수에는 &를 붙인다. 배열의 경우는 []앞에가 주소이기 때문에 &안붙인다.
    //  scanf("%d", &my_numbers[0]); 같은 의미

    printf("%d\n", my_numbers[0]);  // my_numbers[0]의 주소가 my_numbers이다.
    printf("%d\n", my_numbers[1]);
    printf("%d\n", my_numbers[2]);
    printf("%d\n", my_numbers[3]);
    printf("%d\n", my_numbers[4]);

    /* runtime error */
    // my_numbers[5] = 123;     // 6번째 공간을 접근하려고 들기때문에 error발생
                                // 하지만, compile단계에서 error를 잡지않고 runtime에서 잡는다.

    return 0;
}