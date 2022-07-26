/* #pragma 지시자 */

#include <stdio.h>


/*
    #pragma token (ex : once)
*/

// <1>
// #pragma pack(1)      // 전처리 단계에서 padding을 하지마라고 명령
// _Pragma("pack(1)")   // 같은 의미 ("pack(1)"은 문자열이다) , 전처리기가 문자열을 번역하는 과정에서 destringizing을 한다.
                        // destringizing : " "를 제거, 문자열 안에 ", \" 있을 경우 "로 바꿔준다.

// <응용>
// #define PACK1 _Pragma("pack(1)")
// PACK1                // 간단하게 사용할 수 있다.

// <2>
// #pragma warning ( disable : 4477 )   // warning을 사라지게 만든다.
// #pragma warning ( error : 4477 )     // warning을 error처럼 처리

struct s {
    int i;
    char ch;
    double d;
};

int main()
{
    struct s A;
    printf("Size of A is : %ld", sizeof(A));    // 13

    return 0;
}