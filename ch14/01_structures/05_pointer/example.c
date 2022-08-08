#include <stdio.h>
#include <stdlib.h>

struct my_data
{
    int a;
    char c;
    float arr[2];
};

int main()
{
    struct my_data d1 = { 1234, 'A', /* {1.1f, 2.2f} */ };

    d1.arr[0] = 1.1f;
    d1.arr[1] = 2.2f;

    printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);  // 1234 A 6104462488
    printf("%f %f\n", d1.arr[0], d1.arr[1]);                // 1.100000 2.200000
    printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);  // 6104462488 6104462492

    struct my_data d2 = d1; // 배열이 갖고있는 값 복사 (주소는 다르다.)

    printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);  // 1234 A 6104462472
    printf("%f %f\n", d2.arr[0], d2.arr[1]);                // 1.100000 2.200000
    printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);  // 6104462472 6104462476

    return 0;
}