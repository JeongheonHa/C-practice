/* 난수 생성기 모듈 만들기 예제 */
// 컴퓨터는 자체적으로 난수를 만드는 능력은 없다. (때문에 random seed를 설정해준다)

#include <stdio.h>
#include <stdlib.h> // srand() etc. (랜덤 넘버를 생성할 때 필요한 함수들은 stdlib에 들어있다)
#include <time.h>   // time()

int main()
{
    /*
        rand()
        - 0 to RAND_MAX (typically INT_MAX와 같은 값)
        - defined in stdlib.h
    */

    // // srand(1);   // random seed (()안의 입력값에 따라 달라진다.)
    // srand((unsigned int)time(0));    // seed값을 time(0)(시간의 반환값)으로 설정함으로서 매 시간마다 값이 변하는 성질을 이용

    // for (int i = 0; i < 10; ++i)
    // {
    //     printf("%d\n", rand());
    // }

    /* 예제 (유사 난수) */

    unsigned int next = 1;  // seed 값으로 1사용

    for (int i = 0; i < 10; ++i)
    {
        next = next * 1103515245 + 1234;
        next = (unsigned int) (next / 65536) % 32768;
        printf("%d\n", (int)next);
    }

    return 0;
}

