/* 미리 정의된 매크로들 */
// #line, #error

#include <stdio.h>

#include "DifferentFile.h"

void different_function();

int main()
{
    printf("__FILE__: %s\n", __FILE__); // __FILE__은 현재 매크로가 사용된 파일의 이름을 문자열로 바꿔서 출력할 수 있게 해준다. (절대 경로 출력)
    printf("__DATE__%s\n", __DATE__);   // 컴파일이된 날짜
    printf("__TIME__%s\n", __TIME__);   // 컴파일이된 시간
    printf("__LINE__%d\n", __LINE__);   // line number (15)
    printf("__func__%s\n", __func__);   // 사용되는 함수의 이름 (현재는 main)

    different_function();

    different_func_in_different_file();

    /* Not defined in VS */

    printf("__STDC__ %d\n", __STDC__);  // c언어 표준을 만족하는가 ?
    printf("__STD__HOSTED__ %d\n", __STDC_HOSTED__);    // 표준을 더 엄격하게 따르느나 아니냐?
    printf("__STDC_VERSION__ %ld\n", __STDC_VERSION__); // 버전이 몇인지

    #line 7 // 강제로 line number를 7로 바꾼다.
        printf("__LINE__ after #line %d\n", __LINE__);
    
    #line 1 "hello.txt" // 강제로 파일의 이름을 hello.txt로 바꾼다.
        printf("__LINE__ after #line %d\n", __LINE__);
        printf("__FILE__ : %s\n", __FILE__);

    #if __LINE__ != 33  // 현재 line이 33이 아니라면
    // #error Not line 33  // 강제로 compile error를 나게 만든다. (#error)
    #endif

    #if defined(_WIN64) != 1    // WIN64에서 컴파일되지 않는다면 
    // #error Not WIN64 platform   // 강제로 error를 발생
    #endif

    return 0;
}

void different_function()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d\n", __LINE__);
}
