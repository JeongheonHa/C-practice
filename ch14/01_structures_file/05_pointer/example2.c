/* 동적 할당으로 받을 경우 */

#include <stdio.h>
#include <stdlib.h>

struct my_data
{
    int a;
    char c;
    float* arr;
};

int main()
{
    struct my_data d1 = { 1234, 'A', NULL};
    d1.arr = (float*)malloc(sizeof(float) * 2);
    d1.arr[0] = 1.1f;
    d1.arr[1] = 2.2f;

    printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);  // 1234 A 5567965072
    printf("%f %f\n", d1.arr[0], d1.arr[1]);                // 1.100000 2.200000
    printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);  // 5567965072 5567965076

    struct my_data d2 = d1; // d1의 arr과 d2의 arr이 가리키는 주소값이 동일 (같은 메모리 공간의 주소를 기리키도록 한다는 의미)

    printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);  // 1234 A 5567965072
    printf("%f %f\n", d2.arr[0], d2.arr[1]);                // 1.100000 2.200000
    printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);  // 5567965072 5567965076

    return 0;
}