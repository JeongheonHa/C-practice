# include <stdio.h>

extern int el;  // 어딘가 다른 file에 선언되어있는 변수를 사용해라
                // el의 값을 바꿀 경우 모든 파일에 값이 변한다.
// extern int il;   // link error

void testLinkage()
{
    printf("DoSomething called\n");
    printf("%d\n", el);

    el++;
}
