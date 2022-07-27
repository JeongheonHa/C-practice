/* inline function */
// 작은 함수가 여러 차례 반복적으로 실행될 때 실행 속도를 빠르게 끌어올릴 수 있다. ex) for문 안에 작은 사이즈의 함수를 호출하는 경우

#include <stdio.h>
#include <MyHeader.h>
/*
    Function call has overhead (함수가 수행하는 업무 외의 작업) 
    - set up the call, pass arguments(인자 복사), jump to the function code, and return.

    <방법>
    // <1>
    Macro like function

    // <2>
    inline function specifier
    - Suggests inline replacements (함수의 내용을 모두 바꿔달라고 요청 (컴파일러가 거부할 수 도 있다.))
    - Inline functions should be short. (사이즈가 큰 함수의 경우 overhead는 무시할 수 있는 정도의 사이즈이다.)
    - A function with internal linkage can be made inline. (GCC, clang)
    - You can't take its address (inline 함수는 function call overhead를 거치지 않고
                                  코드에 복사 붙여넣기를 하는 것이기 때문에 다른 함수들과는 달리 주소를 가져올 수 없다.)
*/

inline static int foo() // static을 이용해 internal linkage 상태로 만듬
{
    return 5;
}

int main()
{
    int ret;

    ret = foo();    // ret = 5; 인 것 처럼 컴파일 (어셈블리 이용해서 확인해보기)

    printf("Output is : %d\n", ret);

    // <ex>
    // 보통은 header file을 이용하여 inline함수를 만든다.
    // inline함수는 단순히 복사 붙여넣기를 하는 것이기 때문에 정의 부분을 따로 만들지 않고 header file안에 모두 넣어 컴파일러가 최적화할 수 있게 해준다.

    int i = hello();

    printf("%d\n", i);

    printf("%p\n", hello);

    return 0;
}
