#include <stdio.h>

#define TYPE 1

#if TYPE == 1               // 매크로가 1인지 조건을 건다. (조건문과 같은 원리)
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function()
{
    printf("Wrong compile option!");
}
#endif

int main()
{
    my_function();

    return 0;
}