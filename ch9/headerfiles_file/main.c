/* 헤더 파일 */
// 보통 main을 포한한 파일은 파일명을 main.c로 한다.
// c파일을 하나 더 만들어 prototype을 선언하고 
// header파일에는 정의를 넣는다.

// #include <stdio.h> header file에서 이미 선언했기 때문에 필요 X

#include "my_print_function.h"
#include <stdio.h>

int main()
{
    print_hello();
    print_hi();
    print_str("NO one lives forever.");
    print_str("valar morgulis");

    return 0;
}