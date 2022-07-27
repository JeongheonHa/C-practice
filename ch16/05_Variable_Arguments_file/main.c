/* 가변 인수 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h> // Variable Arguments

/*
    Variable Arguments
    - int printf(char const* const _Format, ...);

    ... : ellipsis

    <과정>
    1. Provide a function prototype using an ellipsis

    <ex>
    void   vaf1(int n, ...);                    // ok
    int    vaf2(const char * s, int k, ...);    // ok
    char   vaf3(char c1, ..., char c2);         // Not ok, ...는 마지막에 와야한다.
    double caf4(...);                           // Not ok, 파라미터가 없다.

    2. Create a va_list type variable in th function definition
    3. Use a macro to initialize the variable to an argument list
    4. Use a macro to access the argument list
*/

double average(int, ...);   // 여러 개의 arguements를 하나의 파리미터로 받아오는 법
double average2(char* format_string, ...);

int main()
{
    double a, b;

    a = average(3, 1.1, 2.2, 3.3);
    b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    // <문자열의 경우>
    // a = average2("dd", 1.1, 2.2, 3.3);   // "dd" : 문자열의 글자 수를 센다.
    // b = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    printf("%lf\n%lf\n", a, b);
}

double average(int num, ...)
{
    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, num);  // va_start : 매크로 , ... 앞에있는 마지막 파라미터를 넣어준다. (내용 자체가 중요한 것이 아닌 ...이 들어갈 자리를 알려주기 위함)
    for (i = 0; i < num; i++)
        sum += va_arg(ap, double);  // ...으로 들어오는 인자가 어떤 타입인지 알아야한다.
    va_end(ap);

    return sum / (double)num;
}

double average2(char* format_string, ...)   // printf에 format_string이 들어오면 ...에 들어오는 인자가 몇개인지 어떤 자료형인지를 분석해서 맞춘다.
{
    int num = strlen(format_string);

    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, format_string);
    for (i = 0; i < num; i++)
        sum += va_arg(ap, double);
    va_end(ap);

    return sum / (double)num;
}
    
