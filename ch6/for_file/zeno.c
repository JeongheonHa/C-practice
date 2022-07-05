/* for문을 이용한 zeno's paradox */

#include <stdio.h>

int main()
{
    const double speed = 1.0;   // const로 speed 변수 1.0으로 정의
    const unsigned repeat_max = 10;

    double dt = 1.0;    // 변수 지정
    double time = 0.0;
    double dist = 0.0;

    for (unsigned i = 0; i < repeat_max; ++i)   // unsigned i 변수지정과 동시에 초기화
    {
        dist += speed * dt;
        time += dt;

        printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

        dt *= 0.5;  // *연산자가 /보다 빠르다. 
    }

    return 0;
}

