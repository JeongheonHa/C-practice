/* 불리언형 */
// boolean은 값으로 ture(1), false(0)밖에 올 수 없다. (1,0 -> 1bit)
// 자료형이 가지는 가장 작은 메모리 사이즈는 1byte이기 때문에 1byte의 크기를 갖는다.
// byte는 주소를 배정받을 수 있는 최소 단위이기 때문에

#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("%lu\n", sizeof(_Bool));  // 1byte

    _Bool b1, b2;
    b1 = 0;
    b2 = 1;

    printf("%d %d\n", b1, b2);  // 0 1, bool은 특별한 형식 지정자가 없기때문에 %d사용

    bool b3, b4;
    b3 = true;  // 문자열이 아닌 1이기때문에 1bit 
    b4 = false;

    printf("%d %d\n", b3, b4);  // 1 0

    return 0;
}
