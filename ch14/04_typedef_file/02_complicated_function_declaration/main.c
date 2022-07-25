/* 복잡한 함수를 선언하는 경우 */
// typedef로 선언할 경우 더 편리하다.

#include <stdio.h>

char char3[3] = { 'A', 'B', 'C' };

char (*complicated_function1())[3]  // char[3]의 포인터를 리턴하는 함수
{
    return &char3;
}

typedef char(*FRPTC3())[3];
typedef char(*(PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;

FRPTC3 *fptr2 = complicated_function1;
PTFRPTC3 *fptr3 = complicated_function1;

/* 더 간단하게 만들기 */

typedef char c3[3]; // char 3개짜리 배열을 c3라는 이름의 자료형으로 사용하겠다는 의미

c3* complicated_function2() // char (*complicated_function1())[3] -> c3* complicated_function2() (더 단순하게 만들 수 있다.)
                            // 반환 자료형이 c3의 포인터이다.
{
    return &char3;
}

int main()
{
    char(*ret_val)[3] = fptr1();

    printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);  // A B C

    // c3를 이용한 경우
    c3 *my_c3 = fptr2();

    printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);        // A B C

    return 0;
}
