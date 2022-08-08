/* 라이브러리 */
// properties -> configuration type -> (static library, dynamic library), 디버그 모드와 release 모드 둘 다 적용
// static library : 내가 작성하는 프로그램에 바로 library가 추가가 된다.
// dynamic library : 프로그램 자체가 library를 가지고 있는 것이 아닌 실행할 때 동적으로 가져다 쓴다.

#include "MyLibrary.h"

#include <stdio.h>

void say_hello()
{
    printf("Hello\n");
}

void say_world()
{
    printf("World\n");
}