/* printf */
/*
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    double d = 3.1415926535897932384626433832795028841971693993751058209749445923078164;

    printf("%c\n", 'A');    // 한글자를 표현할떄는 ''
    printf("%s", "I love you\n");
    printf("Even if there's a small chance, \
we owe this to everyone who's not this room to try.\n");    // 아래에 쓰고싶을 때는 \사용

    printf("\n");
    printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX);     // 1004 1234 2147483647 -1, unsigned integer경우 error발생 (overflow)
    printf("%u %u %u\n", 1024, -1, UINT_MAX);   // 1024 4294967295 4294967295, -1을 %u로 출력하려하기 때문에 error발생 (%u -> %d)

    printf("\n");
    printf("%f %f %lf\n", 3.141592f, d, d);     // lf에서 l은 무시, double 자료형에 formatted specifier는 %f (scanf에서는 %lf)
    printf("%a %A\n", d, d);    // 0x1.921fb54442d18p+1 0X1.921FB54442D18P+1
    printf("%e %E\n", d, d);    // 3.141593e+00 3.141593E+00

    printf("\n");
    printf("%g %g\n", 123456.789, 1234567.89);  // %g : %f와 %e 중 적합한거 알아서 사용 (%G : %f, %E)
    printf("%G %G\n", 123456.789, 1234567.89);
    printf("%g %g\n", 0.00012345, 0.000012345);
    printf("%G %G\n", 0.00012345, 0.000012345);

    printf("\n");
    printf("%o\n", 9);  // 11, 8진수 표현
    printf("%p\n", &d); // x16d73b4c0, d메모리의 주소를 표현

    printf("\n");
    printf("%x %X\n", 11, 11);  // b B, 16진수 표현
    printf("%%\n");  // %기호 자체를 출력

    printf("\n");
    printf("%9d\n", 12345);     //     12345, %9d : 9만큼의 자리수로 채운다.
    printf("%09d\n", 12345);    // 000012345, %09d : 앞에가 비어있을 경우 0으로 채운다. 
    printf("%.2f\n", 3.141592);     // 3.14, %.2f : 소수점 이하 자리를 2자리 수까지만 출력
    printf("%.20f\n", d);     // 3.14159265358979311600, f의 메모리 공간의 한계로인해 표현하지 못할경우 0으로 출력

    printf("\n");
    int n_printed = printf("Smartphone");   // Smartphone
    printf("%u\n", n_printed);  // 10
    // printf 함수의 return값은 출력된 문자의 개수

    return 0;
}
*/

/* formatted specifier */ 
// %[flags][width][.precision][length]converse specifier 형태로 적용가능
// ex) printf("%+10.5hi", 345);
#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    /* flags */

    // - : 왼쪽으로 붙여서 정렬, 안쓸경우 오른쪽으로 붙여서 정렬 (width랑 같이 사용)
    // + : 양수일때도 +기호를 붙여라
    // (space) : 
    // # : 8진수, 16진수 등을 표현할 때 0, 0x, 0X를 표현해줘라.
    // 0 : width를 지정을 했을 때 남는 자리를 0으로 채워라.
    /* width */
    // (number) : 문자열 길이를 지정
    // * : width를 control string이 아닌 뒤에 parameter로 표현
    
    
    printf("%10i\n", 1234567);  //    1234567
    printf("%-10i\n", 1234567); // 1234567
    printf("%+i %+i\n", 123, -123);     // +123 -123
    printf("% i \n% i\n", 123, -123);   //  123 -123
    printf("%X\n", 17);     // 11
    printf("%#X\n", 17);    // 0X11
    printf("%05i\n", 123);  // 00123
    printf("%*i\n", 7, 456);    //     456, 7이 *자리로 들어간다.
    

    /* .precision (정밀도) */
    // .number , .*

    printf("%.3d\n", 1234);     // 1234, 최소숫자의 개수가 3으로 1234는 4개이므로 그대로 출력
    printf("%.5d\n", 1234);     // 01234, 최소숫자의 개수가 5이므로 오른쪽 정렬로 비어있는 부분을 0으로 채워서 출력
    printf("%.3f\n", 123456.234567);    // 123456.235, f의 경우 소수점의 자리수 지정 (반올림 적용)
    printf("%10.3f\n", 123.45678);      //    123.457, 오른쪽 정렬로 소수점 자리수가 3인 10개의 자리수 표현
    printf("%010.3f\n", 123.45678);     // 000123.457, 빈칸 0으로 출력
    printf("%.5s\n", "ABCDEFGHIJKLMNOP");   // ABCDE, string과 사용할 경우 문자의 개수 지정
    printf("%.s\n", "ABCDEFGHIJKLMNOP");    // 숫자를 안쓸경우 숫자 0을 넣을 것과 같은 작용

    /* Length */

    printf("%hhd %hd %d\n", 257, 257, 257);     // 1 257 257, hhd의 경우 overflow되어 1 출력
    printf("%d %ld %lld\n", INT_MAX + 1, INT_MAX, 2147483648LL + 1);   // -2147483648 2147483648 2147483649, 
    // LL : LongLongliteral이라는 것을 표현

    return 0;
    
}


