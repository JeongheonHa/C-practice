/* 고정너비 정수형 */
// 자료형은 각 자료형의 최소 메모리 크기만을 규정하기때문에 한 시스템에서 만든 코드가 
// 다른 시스템에서 잘 작동하지 않을 수 있기때문에 변수, 자료형의 메모리 사이즈를 고정
// 할 수 있도록 해준다.

#include <stdio.h>
#include <stdint.h>     // 고정너비 정수형을 include
#include <inttypes.h>   // 고정너비 정수형에 맞는 형식 지정자를 보다 쉽게 사용할 수 있게 include

int main()
{
    int i;
    int32_t i32;    // 32 bit integer로 명확히 규정
    int_least8_t i8;    // 적어도 8bit를 가지는 정수형
    int_fast8_t f8;     // 8bit에서 가장 빠른 정수형
    intmax_t imax;      // signed integer에서 가장 큰 사이즈의 메모리를 사용하는 정수형
    uintmax_t uimax;    // unsigned integer에서 가장 큰 사이즈의 메모리를 사용하는 정수형

    i32 = 1004;

    printf("me32 = %d\n", i32); 
    printf("me32 = %" "d" "\n", i32);
    printf("me32 = %" PRId32 "\n", i32);    // " "안의 형식지정자를 나누어서 매크로(PRTd32)를 이용해 d부분을 고정너비 정수형에 맞게 작성하면 된다.
                                            // PRI : print

    return 0;
}