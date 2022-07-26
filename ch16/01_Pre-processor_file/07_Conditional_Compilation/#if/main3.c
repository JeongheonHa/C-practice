#include <stdio.h>
// 플렛폼에 맞춰서 코드가 다른 코드인 것처럼 일부를 바꿔서 코딩을 할 수 있다.

void say_hello()
{
#ifdef _WIN64               // 각각의 이름들은 컴파일러가 각각의 운영체제에 맞게 컴파일하기위해 전처리단계에서 어디선가 해당 이름을 가져온다.
// #if edfined (_WIN64) 와 동일한 코드
    printf("Hello, WIN64");
#elif _WIN32
    printf("Hello, WIN32");
#elif __linux__
    printf("Hello, linux");
#endif
}

int main()
{
    say_hello();

    return 0;
}