/* 구조체를 함수로 전달하는 방법 */

#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
    char   bank_name[FUNDLEN];
    double bank_saving;
    char   fund_name[FUNDLEN];
    double fund_invest;
};

double sum(const struct fortune* my_fortune);

int main()
{
    struct fortune my_fortune = {
        "Wells - Fargo",
        4032.27,
        "JPMorgan Chase",
        8543.94
    };

    printf("Total : $%.2f.\n",
        sum(&my_fortune)
    );

    // struct fortune my_fortune2;  // 대입하면 복사
    // my_fortune2 = my_fortune;

    return 0;
}

double sum(const struct fortune* mf)   // 파라미터로 받는 변수에 복사를 하는 것이므로 주소가 다르다.
                                       // 결국 스택에 복사를 하는 것이기 때문에 함수의 stack frame내에 있는 동안 메모리의 양을 많이 차지한다. 
                                       // 따라서, 파라미터로 포인터를 받아와 주소만을 복사하는 방법을 선호한다.
{
    return mf->bank_saving + mf->fund_invest;
}