/* 포인터 */
// 많은 양의 데이터를 저장하는 주소를 가르킨다.
// 변수의 주소값를 저장하는 변수
// ex) int *a_ptr = &a;
// int형 a변수의 주소를 저장하기 위해 int를 선언
// a_ptr또한 변수이며 주소를 저장하는 데이터이다.
// 장점 : 데이터가 큰 경우에 해당 메모리를 복사하는 것이 아닌 위치를 가리켜 가져오는 것이기때문에 메모리를 적게 차지한다.

#include <stdio.h>

int main()
{
    int a, b;

    a = 123;

    int *a_ptr;

    a_ptr = &a;

    printf("%d %d %p\n", a, *a_ptr, a_ptr);  //123 123 0x16f9cb508 

    // *ptr값 덮어쓰기
    *a_ptr = 456;   // 주소가 저장된 데이터에서 a의 메모리 공간에 접근해 값을 변경
                    // 주소는 동일
    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //  b = a_ptr; 가능은 하지만 사용 X
    b = *a_ptr; // 값을 가져와서 값을 b에 저장

    printf("%d\n", b);  // b는 단순히 값만을 저장하기 때문에 포인터와 엮이지 않는다.

    *a_ptr = 789;

    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);

    return 0;
}