/* arguement & parameter */
// argument : values (인수, 인자)
// parameter : variables (매개변수)
#include <stdio.h>

void draw(int n);   // ANSI function prototype declaration, 들어가는 것과 나가는 것이 무엇인지 보여주는 것
                    // draw함수가 main함수 밑에 있기 때문에 전체적으로 선언을 해줘야 main함수가 draw함수를 사용할 수 있다.
                    // 함수의 body는 따로 선언 되어야한다.
int main()
{
    int i = 5;
    char c = '#';   // 35
    float f = 7.1f;

    draw(i);    // draw함수를 호출하는 측면에서는 5라는 값을 i에 넣는 것이기때문에 arguement라 한다. 
    draw((int)c);
    draw((int)f);

    return 0;
}

void draw(int n)    // int n : 변수(parameter), function draw가 variable n에 대해서 매개변수화 되어있다.
{
    while (n-- > 0)
        printf("*");
        printf("\n");
}