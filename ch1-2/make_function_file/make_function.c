#include <stdio.h>

void Hello(); // prototyping (function declartion), void : 아무기능이 없는 자료형 타입, 함수의 경우 ()로 표현
              // OS(Operating System)이 프로그램을 실행할때는 무조건 main부터 실행시키기 때문에 main전에 함수선언을 해준다.
int main()
{
    Hello();

    return 0;
}
void Hello() // void는 return생략가능 or return; , function definition
{
    printf("Hello\n");
}