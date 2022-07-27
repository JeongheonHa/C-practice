/* assert 라이브러리 */
// 반드시 만족해야할 조건에 assert()를 하면 만족하지 않을 경우 debug모드에서 문제가 생긴다.

#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide(int a, int b);
// _Static_assert(CHAR_BIT == 9, "9-bit char assumed"); // 빌드를 할때 error를 잡아준다.

int main()
{
    int a, b;
    int f = scanf("%d%d", &a, &b);

    printf("a / b = %d", divide(a, b));

    return 0;
}

int divide(int a, int b)
{
    // <1>
    assert(b != 0); // Release 모드에서 실행을 할 경우 assert가 무시가 된다.

    // <2>  overhead가 발생
    // if (b == 0) {
    //      printf("Cannot divide\n");
    //      exit(1);
    // }

    return a / b;
}
