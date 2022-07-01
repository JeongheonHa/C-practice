/* ASCII Chart */
// https://en.cppreference.com/w/c/language/ascii
// 문자도 숫자로 인식 

#include <stdio.h>

int main()
{
    char c = 'A';   // char타입 변수에는 문자가 하나씩 들어간다.
    char d = 65;    // d = 'A'

    printf("%c %hhd\n", c, c);  // A 65, %c는 문자 출력하는 형식지정자, %hdd : 숫자 출력하는 형식지정자
    printf("%c %hhd\n", d, d);  // A 65

    printf("%c \n", c + 1);     // B

    /* escape sequence */
    // /뒤에 있는 것을 출력하겠다는 의미

    // 알림기능 (\a) //
    char a = '\a';
    printf("%c", a);    
    printf("\07");      // 8진수로 표현
    printf("\x7");      // 16진수로 표현

    // backspace 기능 (\b) //
    float salary;
    printf("$______\b\b\b\b\b\b");  

    // 줄맞춤 기능 (\t) //
    printf("AB\tCDEF\n");   
    printf("ABC\tDEFG\n");

    // 여러 기능 //
    printf("\\ \' Hey\' \"Hello\" \?\n");   // \ ' Hey' "Hello" ?
    
    return 0;

}
