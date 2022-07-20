/* 멀티 쓰리딩 */

/*
    < process >

    Main Thread
        o         
        |         Thread 0
        o ---------- o 
        |            |         Thread 1
        o -----------|----------- o
        |            |            |         Thread 2
        o -----------|------------|----------- o
        |            |            |            |
        |            |            |            |
        o ---------- o            |            |
        |                         |            |
        o ----------------------- o            |
        |                                      |
        o ------------------------------------ o
        |
        |
        o
*/

/*
    - 동시 다발적으로 진행되는 상황 (병렬 처리)
    - 같은 함수를 여러개의 thread가 동시해 작동을 시킬 경우 함수 내의 지역 변수는 어떤 storage class를 갖는 가?
     -> 메모리 상에는 함수를 실행시키기 위한 데이터가 3 copy가 존재하고 그 함수에 들어있는 변수들도 3 copy가 생긴다.
    - 하나의 전역 변수를 여러개의 thread가 동시에 접근할 경우
     -> 데이터를 메모리에서 cpu로 전송하면 cpu내의 레지스터라는 임시 저장 공간에 올려놓고 작업을 하고 다시 데이터를 메모리에 보내는데
        데이터가 cpu내에 있는 동안 메모리 공간의 데이터를 다른 thread가 바꿀 경우 문제가 발생
*/

// c언어 표준에서는 thread기능을 제공해주지 않기때문에 운영체제가 제공하는 api를 사용

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // (gcc 제공)
#include <stdatomic.h>  // _Atomic
// #include <windows.h> (윈도우에서만 가능)

_Atomic int acnt = 0;   // atomic type qualifier
                        // _Atomic 키워드를 사용할 경우 하나의 전역 변수에 여러개의 thread가 동시에 접근하여 racing하는 경우를 없애준다.

void *myThreadFun(void * vargp)
{
    int n = 1;  //thread storage duration
    for (int j = 0; j < 10; ++j)
    {
        sleep(1);
        acnt += n;  // atomic으로 정의된 변수의 연산은 느리다는 단점이 있다.
                    // 한 thread 안에서 빈번하게 연산하는 경우 사용하지 않는다.
        printf("Printing from Thread %d %llu\n", acnt, (unsigned long long)&n);
    }

    return NULL;
}

int main()
{
    pthread_t thread_id1, thread_id2;   // thread 식별 (identification)

    printf("Before Thread\n");

    // <1>
    // 일시적으로 myThreadFun 함수가 메모리와 cpu에 2 copy가 작동한다. 
    // thread 1, thread 2에서 지역 변수가 사용하는 메모리를 각자 갖고있다.
    pthread_create(&thread_id1, NULL, myThreadFun, NULL);   // myThreadFun을 실행시키는 thread를 실행시키고 
                                                            // 그 thread에 대한 식별자를 &thread_id1 자리에 에 넣어 준다
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);

    // <2>
    // thread들이 일이 끝나는 것을 기다렸다가 join시킨다.
    // ex) main thread가 여러 thread에 일을 시켜놓고 먼저 끝나버리면 안된다.
    pthread_join(thread_id1, NULL); 
    pthread_join(thread_id2, NULL);

    printf("After Thread\n");
    printf("Atomic %d\n", acnt);

    return 0;
}