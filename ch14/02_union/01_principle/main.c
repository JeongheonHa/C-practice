/* 공용체의 원리 */

#include <stdio.h>

int main()
{
    /*
        Union
        - store different data types in the same memeory space (다른 타입의 데이터들이 같은 메모리 공간을 사용하도록 하는 것)
        - Structure vs Union
        구조체 : member들이 메모리를 따로 따로 저장
        공용체 : member들이 메모리를 다 같이 저장
    */

    union my_union {
        int    i;
        double d;
        char   c;
    };

    union my_union uni;

    printf("%zd\n", sizeof(union my_union));    // 8 (구조체라면 패딩 포함 16byte가 나왔을 거지만 공용체는 가장 큰 사이즈를 사용)
    printf("%lld\n", (long long)&uni);          // 6156186768
    printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);    // 6156186768 6156186768 6156186768 
                                                                                            // 메모리 공간을 공유

    union my_union save[10];

    printf("%zd\n", sizeof(save));              // 80

    /*
        Union of different types
    */

    union my_union uni1;

    uni1.c = 'A';
    printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);  // A 41 -392429503
    // 0xcccccc41 = -39242950
    uni1.i = 0;
    uni1.c = 'A';
    printf("%c %c %d\n", uni1.c, (int)uni1.c, uni1.i);  // A A 65
    // 0x00000041 = 65

    uni1.d = 1.2;
    printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);   // 858993459 1.200000 51 3
    // 33 33 33 33 33 33 f3 3f
    // 0x3ff3333333333333 = 1.19999999999999995559107901499E0
    // 0x33333333 = 39242950 (decimal)
    // 0x33 = 51, '3'

    /*
        Initializing unions
    */

    // <1>
    union my_union uni2 = uni1;             //copy another union
    union my_union uni3 = { 10 };           // first element (member) only (첫번째 멤버 처럼만 초기화할 수 있다.)
    union my_union uni4 = { .c = 'A' };     // designated initializer
    // union my_union uni5 = { .d = 1.23, .i = 100 };  // do not recommend (오직 하나만 초기화)

    // printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);

    // <2>
    uni.i = 123;
    uni.d = 1.2;
    uni.c = 'k';

    printf("%d %f %c\n", uni.i, uni.d, uni.c);  // 858993515 1.200000 k

    // <3>
    union my_union* pu = &uni;  // pointer to union
    int x = pu->i;              // -> operator, same as x = fit.digit

    uni.c = 'A';
    double real = 3.14 * uni.d; //do not recommend (c로 받고 d로 쓰면 의도를 알 수 없다.)

    return 0;
}