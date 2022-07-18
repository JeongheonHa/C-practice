/* linkage */
// 컴파일러가 translation 하는 최소 단위는 file이다.
// 컴파일러는 file을 따로 translation하기 때문에 서로 다른 c-file이 무슨 작업을 하는지 서로 알 수 있는 방법이 없다.
// linker가 file과 file을 연결시켜준다.

#include <stdio.h>

/* 
    Linkage

    Variable with block scope, function scope, or function prototype
    - No linkage

    File scope variables
    - External or internal linkage

    global variable (전역 변수) : 어느 translation unit에서든 사용할 수 있기때문에 global variable이다.
*/

int el;     // file scope with external linkage (global variable)
            // 모든 file 전체에 사용할 수 있기때문에 흔히 전역 변수라고 부른다. (file scope내에서만 사용할 수도 있다.)

static int il;  // static : scope를 제한한다. (다른 file scope에서 사용할 수 없다.)

void testLinkage(); // 다른 파일에 있는 tesLinkage()함수를 사용하기 위해 프로토타입 선언

int main()
{
    el = 1024;

    testLinkage();

    printf("%d\n", el); // 1024 출력, second.c에서 el++로 인해 1025 출력

    return 0;
}