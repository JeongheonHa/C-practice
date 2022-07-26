#include <stdio.h>

#define REPORT  // 매크로 이름만 정의되어 있는 것을 empty macro라고 부른다.

int sum(int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; ++k)
    {
        s +=k;

#ifdef REPORT   // debug 모드일 때와 release 모드일 때를 구분하여 사용할 수 도 있다. debug 모드는 빌드를 할 때 debug에 필요한 기능을 전처리에 포함시킨다.
        printf("%d %d\n", s, k);
#endif
    }

    return 0;
}

int main()
{
    printf("\n%d \n", sum(1, 10));

    return 0;
}