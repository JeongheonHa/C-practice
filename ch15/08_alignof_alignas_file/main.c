/* 메모리 줄맞춤 */

#include <stdio.h>
#include <stdalign.h>   // alignas, alignof

int main()
{
    /* alignof() */

    printf("Alignment of char = %zu\n", alignof(char)); // align을 할때 최소 단위가 1byte라는 뜻
    printf("alignof(float[10) = %zu\n", alignof(float[10]));    // 각각의 원소를 몇 byte로 align을 해줘야하는지 
    printf("alignof(struct{char c; int n;}) = %zu\n", alignof(struct {char c; int n;}));
    // 둘 중에 더 큰 사이즈로 align

    /* alignas */
    
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    // char cz;
    // char _Alignas(double) cz;
    char alignas(16) cz;

    printf("Char alignment: %zd\n", alignof(char));
    printf("double alignment : %zd\n", alignof(double));

    // 8개 블록에 줄맞춤된 형태 (주소의 나머지가 0)
    printf("&dx: %p %lld\n", &dx, (long long)&dx % 8);
    printf("&ca: %p %lld\n", &ca, (long long)&ca % 8);
    printf("&cx: %p %lld\n", &cx, (long long)&cx % 8);
    printf("&dz: %p %lld\n", &dz, (long long)&dz % 8);
    printf("&cb: %p %lld\n", &cb, (long long)&cb % 8);
    printf("&cz: %p %lld\n", &cz, (long long)&cz % 8);

    // 배열의 만들때도 사용 가능
    unsigned char alignas(long double) c_arr[sizeof(long double)];
}