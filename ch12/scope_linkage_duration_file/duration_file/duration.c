#include <stdio.h>

/*
    Storage duration : 메모리의 지속 기간
    - static storage duration : 프로그램이 시작할 때 메모리에 자리를 잡고 끝날 때까지 머문다는 의미
    // 변수 선언할때의 static과 차이 : scope가 넓어지지 않게 막는다. // static하게 메모리에 자리를 잡고 머문다.
    - automatic storage duration : 보통 지역 변수를 의미
    - allocated storage duration : 동적 할당과 관련
    - thread storage duration : multi thread (기초강의에서는 다루지 않음)
*/

void count()
{
    int ct = 0;
    printf("count = %d\n", ct);
    ct++;
}

void static_count()
{
    static int ct = 0;  // ct라는 변수는 프로그램이 시작될 때 메모리에 들어오고 프로그램이 끝날 때까지 계속 유지 (다시 선언하지 않는다)
    printf("static count = %d\n", ct);
    ct++;
}

int main()
{
    count();
    count();
    static_count();
    static_count();

    return 0;
}
