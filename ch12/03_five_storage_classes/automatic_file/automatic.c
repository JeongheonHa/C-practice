/* Automatic storage */

#include <stdio.h>

/*
    Automatic storage class
    - automatic storage duration, block scope, no linkage
    - any variable declared in a block or function header
*/

void func(int k);

int main()
{
    auto int a; // auto 생략 가능, keyword auto : a storage-class specifier
    a = 1024;
    auto int b = a * 3; // 지역 변수들은 초기화를 무조건 해준다.
    // BSS Segment에 들어있는 전역 변수들 같은 경우에는 처음 한번만 초기화를 하면 되기 때문에 컴파일러가 초기화를 해주지만
    // stack에 저장되는 지역 변수들 같은 경우에는 빈번히 왔다갔다하기 때문에 들어갈때 마다 매번 0으로 초기화를 할 경우 
    // computing time을 먹기 때문에 비 효율적이다.

    int i = 1;
    int j = 2;

    printf("i %lld\n", (long long)&i);

    {
        int i = 3;  // i라는 identifier가 곂칠 경우 안쪽에 있는 i를 의미하고 바깥쪽 i는 name hiding이 된다.
                    // (바깥 i가 사라지는 것이 아닌 이름이 없어졌기때문에 못 부르는 것뿐 메모리는 살아있다.)
        printf("i %lld\n", (long long)&i);

        printf("i = %d\n", j);  // j is visiable here, 바깥 영역에서 j를 선언했기 때문에 안쪽 영역에서 사용 가능 (stack 원리 생각)
    }

    printf("i %lld\n", (long long)&i);  // 어떤 i를 출력하는지 확인

    for (int m = 1; m < 2; m++) // for 문에서 선언된 변수 또한 automatic이며 m의 duration은 ;를 만날때 까지이고 {}가 있다고 생각
        printf("m %lld\n", (long long)&m);
    
    func(5);    // 같은 scope내에 있지만 함수를 호출할 경우 body가 있는 함수로 이동되면서 stack frame자체가 바뀐다.

    for (int m = 3; m < 4; m++)
    {
        printf("m %lld\n", (long long)&m);
    }

    return 0;
}

void func(int k)    // 이 함수내에서 사용한 변수들은 function이 끝나면 stack메모리 공간에서 사라진다 (효율적)
{
    int i = k * 2;

    printf("i %lld\n", (long long)&i);
}