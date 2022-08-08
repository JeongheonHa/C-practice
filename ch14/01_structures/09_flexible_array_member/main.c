/* 신축성있는 배열 맴버 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        flexible array member (struct hack in GCC)
    */
    // values[]로부터 시작하는 배열로서 사용 (동적 할당과 유사, (단, values 자체가 메모리를 차지하지는 않는다.))
    struct flex
    {
        size_t count;   // unsigned long size
        double average;
        double values[];    // flexible array memeber(반드시 마지막 member이어야 한다)
    };

    const size_t n = 3;

    struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));    // 사용하고싶은 배열의 길이만큼 동적 할당을 받는다.
    if (pf == NULL) exit(1);

    printf("\nFlexuble array member\n");
    printf("Sizeof struct flex %zd\n", sizeof(struct flex));    // Sizeof struct flex 16
    printf("Sizeof *pf %zd\n", sizeof(*pf));                    // Sizeof *pf 16
    printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double));    // Sizeof malloc 40

    printf("%lld\n", (long long)pf);            // 5334122624
    printf("%lld\n", (long long)& pf->count);   // 5334122624
    printf("%zd\n", sizeof(pf->count));         // 8 (size_t)
    printf("%lld\n", (long long)& pf->average); // 5334122632
    printf("Address of pf->values %lld\n", (long long)& pf->values);    // Address of pf->values 5334122640
    printf("Value of pf->values %lld\n", (long long)pf->values);        // Value of pf->values 5334122640
    // printf("Sizeof pf->values %zd\n", sizeof(pf->values));              // Sizeof pr->values 0

    pf->count = n;
    pf->values[0] = 1.1;
    pf->values[1] = 2.1;
    pf->values[2] = 3.1;

    pf->average = 0.0;
    for (unsigned i = 0; i < pf->count; ++i)
        pf->average += pf->values[i];
    pf->average /= (double)pf->count;

    printf("Average = %f\n", pf->average);

    /*
        구조체에서의 포인터로 동적 할당 받는 경우
    /*

    /*
    struct nonflex
    {
        size_t count;
        double average;
        double* values; (포인터 자체의 메모리를 차지한다.)
    };

    struct nonflex nf;
    nf.value = (double*)malloc(sizeof(double) * n); // heap어딘가에 생겨난 메모리 공간을 할당 받고 
                                                    // 그걸 배열로서 사용할 수 있는 동적 할당 배열이 생겨나는 구조
    */

    // <비교>
    /*
        flexible array member를 사용하는 경우
        - 멤버와 연속된 메모리를 주기 때문에 어디서부터 시작하는지 알 수 있다.
        - values[] 자체가 메모리를 차지하지않는다.

        구조체에서의 포인터로 동적 할당 받는 경우
        - 마지막 멤버가 가리키는 동적 할당으로 받은 메모리 공간이 어디에 있는지 알 수 없다. (in heap)
        - 포인터 자체의 메모리를 차지한다.


        struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
        if (pf2 == NULL) exit(1);

        *pf2 = *pf1;    // Don't copy flexible members, use memcpy() instead
                        // 컴파일러 입장에서는 대입을 했을 때 16byte만 복사를 해주기 때문에 뒤의 추가로 할당한 배열은 복사하지 않는다.
                        // 컴파일러 입장에서는 알 수 없다.
                        // (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double)) 메모리 전체에 대해서 memcpy()를 하는 것이 좋다.
        
        free(pf);
        free(pf2);
    */

    return 0;
}