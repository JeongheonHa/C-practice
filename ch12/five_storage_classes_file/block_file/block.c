/* 블록 영역의 정적(static) 변수 */
/*
    storage class       memory segment      duration        scope       linkage         how declared
    ----------------------------------------------------------------------------------------------------------------
    고정적, 연결 없음       데이터 or BSS           고정적         블록 안        없음         블록 안에서 static 키워드 사용
    (static with no linkage)
    ----------------------------------------------------------------------------------------------------------------
*/
// linkage가 없지만 메모리가 있기때문에 접근 (포인터 등) 할 수 있다.

#include <stdio.h>

void count()
{
    int ct = 0; // 함수가 끝나면 ct라는 변수는 stack 메모리 공간에서 사라진다.
    printf("count = %d %lld\n", ct, (long long)&ct);
    ct++;
}

void static_count()
{
    static int ct = 0;  // data 나 BSS같이 프로그램이 시작해서 끝날 때까지 static하게 유지가되는 영역에 메모리를 저장
    /* 주의 */
    // static int ct;
    // ct = 0;
    // 문법적으로 많이 달라진다. (다른 의미)
    printf("static count  = %d %lld\n", ct, (long long)& ct);
    ct++;
}

/* 두함수 차이 */
// 첫번째 함수는 변수가 함수가 호출 될 때 마다 매번 초기화가 되지만
// 두번째 함수는 static을 통해 오직 한번만 초기화를 진행한다.

void count_caller()
{
    count();
}

void static_count_caller()
{
    static_count();
}

/* 함수의 파라미터에 static을 선언한 경우 */
/*
    int func(static int i)   // error 발생
    {

    }
    파라미터 변수는 함수가 실행이 될 때 stack frame안에 자신의 메모리를 배정을 받는 구조인데 
    static을 사용한다는 것은 파리미터 변수를 static한 공간에 넣겠다는 의미이므로 맞지 않다.
*/

/* 포인터를 사용하는 경우 */
/*
    // 보통은 반환할 때 값을 반환을 하고 받는 쪽에서 이미 메모리 공간을 갖고 있어 복사를 하는 형태이지만 포인터를 반환을 하는 경우도 꽤 있다.
    // ex) hardware관련 api를 사용할 때, 마우스를 제어할 수 있는 포인터를 가져오는 경우 등등

    // <1> 이런 방식의 코드는 절대 사용하지 않는다.
    // 받는 쪽에서 포인터를 받는다는 것은 그 메모리에 대해서 무언가를 작업을 하고 싶을 때 받는다는 것인데
    // 지역 변수 ct의 포인터를 반환하지만 지역 변수 ct는 함수가 끝나면 사라져 버린다.
    int* count()
    {
        int ct = 0; 
        printf("count = %d %lld\n", ct, (long long)&ct);
        ct++;

        return &ct;
    }

    // <2> 
    // static을 사용하는 경우 메모리가 유지가되어 주소값을 반환하여서 변수 ct에 접근할 수 있지만 함수를 만들기 보다는 차라리 전역 변수를 사용한다. (결국 사용하지 않는다)
    int* static_count()
    {
        static int ct = 0;  
        printf("static count  = %d %lld\n", ct, (long long)& ct);
        ct++;

        return &ct;
    }
*/


int main()
{
    count();        // count = 0 6094042140
    count();        // count = 0 6094042140
    // 두개의 주소가 같은 이유는 연속적으로 count함수를 호출해서 stack frame이 생겼다가 사라진 공간에 다시 생성 때문에 같은 것 뿐이다. 
    count_caller(); // count = 0 6094042124, 다른 함수 내에서 count함수를 호출할 경우 주소가 다르다

    static_count();         // static count  = 0 4372873216
    static_count();         // static count  = 1 4372873216
    static_count_caller();  // static count  = 2 4372873216
   
    // 레이 아웃 전체로 봤을 때 두 경우의 메모리 주소가 멀리 떨어져 있다. (stack vs (data or BSS))

    return 0;
}