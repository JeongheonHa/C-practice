/* #include 와 헤더 파일 */
// 표준 라이브러리의 경우, 외부에서 라이브러리를 가져오는데 일방적으로 사용하기만 하는 경우 < >
// 내가 만든 코드를 가져와서 사용할 경우 " "
#include <stdio.h>
#include "my_functions.h"
#include "my_structures.h"
#include "my_macros.h"   // path "my_headers/my_macros.h"

extern int status;

int main()
{
#include "hello_world.h"    // 전처리기가 헤더 파일의 있는 코드를 복사 붙여넣기 한다. (함수안에 include가 들어가는 것은 절대 안된다.)

    printf("PI = %f", PI);

    printf("%p %d\n", &status, status);

    print_status();

    printf("%d\n", multiply(51, 2));

    printf("main()\n");
    printf("Static function address %p\n", multiply);
    printf("Static variable addess %p\n", &si);
}