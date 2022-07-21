/* 구조체의 메모리 할당 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Well aligned structure
    */

    struct Aligned
    {
        int a;
        float b;
        double c;
    };

    /*
        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
        |int a|float b|      double c       |
        4 + 4 + 8 = 16
    */

    struct Aligned a1, a2;

    printf("struct Aligned a1\n");
    printf("Sizeof %zd\n", sizeof(struct Aligned)); // Sizeof 16 (struct Aligned을 넣어도 되고 변수 a1을 넣어도 된다)
    printf("%lld\n",(long long)& a1);               // 6171047088
    printf("%lld\n",(long long)& a1.a);             // 6171047088
    printf("%lld\n",(long long)& a1.b);             // 6171047092   (4byte씩 차이가 난다)
    printf("%lld\n",(long long)& a1.c);             // 6171047096

    printf("\nstruct Aligned a2\n");
    printf("Sizeof %zd\n", sizeof(a2));             // Sizeof 16
    printf("%lld\n",(long long)& a2);               // 6171047072
    printf("%lld\n",(long long)& a2.a);             // 6171047072
    printf("%lld\n",(long long)& a2.b);             // 6171047076
    printf("%lld\n",(long long)& a2.c);             // 6171047080

    /* 
        padding (struct member alignment) 
        - 1 word : 메모리와 CPU가 데이터를 주고 받는 메모리의 최소 단위 (4 bytes in x86, 8 bytes in x64)

        - 1bit : 정보를 표현하는 최소 단위, 8bit : 주소를 배정하는 최소 단위
    */

    // <1>
    struct Padded1
    {
        char a;
        float b;
        double c;
    };

    /*
        <without padding>
        
        0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 (8byte씩 메모리를 전송하는 경우)
       |a|float b|     double c     | ?  ?  ?    (한번 보낼 때 double c의 데이터가 짤린다)
       1 + 4 + 8 = 13
    */

    /*
       <with padding>
       0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
      |char a |float b|      double c       |    (double c의 데이터가 짤리지 않게 빈공간(?)을 앞에 넣어준다)
      4(char?) + 4 + 8 = 16 // 컴파일러가 char 부분에 3byte를 넣는다.
    */

    struct Padded1 p1;

    printf("\nstruct Padded1 p1\n");
    printf("Sizeof %zd\n", sizeof(p1));             // Sizeof 16
    printf("%lld\n",(long long)& p1);               // 6091371632
    printf("%lld\n",(long long)& p1.a);             // 6091371632
    printf("%lld\n",(long long)& p1.b);             // 6091371636
    printf("%lld\n",(long long)& p1.c);             // 6091371640

    // <2>

    struct Padded2
    {
        float a;
        double b;
        char c;
    };

    /*
        |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
        |    float a    |      double b       |         char c        |
        8(float?) + 8 + 8(char?) = 24 (double의 데이터가 짤리지 않게하기위해 float, char 에 패딩을 한다.)
        <1> , <2> 은 같은 구조체이지만 멤버의 순서가 바뀌었다는 이유만으로 패딩으로 인해 메모리 공간을 더 많이 차지한다. (*구조체 만들시 순서 주의*)
    */

    struct Padded2 p2;

    printf("\nstruct Padded1 p2\n"); 
    printf("Sizeof %zd\n", sizeof(p2));             // Sizeof 24
    printf("%lld\n",(long long)& p2);               // 6091371608
    printf("%lld\n",(long long)& p2.a);             // 6091371608
    printf("%lld\n",(long long)& p2.b);             // 6091371616
    printf("%lld\n",(long long)& p2.c);             // 6091371624

    // <3>  member가 배열인 경우

    struct Person
    {
        char name[41];
        int age;
        float height;
    };

    struct Person mommy;

    printf("\nstruct Person\n");
    printf("Sizeof %zd\n", sizeof(mommy));          // Sizeof 52    // 41(padding + 3) + 4 + 4 = 49? (52)
    printf("%lld\n", (long long)& mommy.name[0]);   // 6092665956 (44byte)
    printf("%lld\n", (long long)& mommy.age);       // 6092666000
    printf("%lld\n", (long long)& mommy.height);    // 6092666004

    // <4> 구조체의 배열
    struct Person f[4];

    printf("Sizeof a structure array %zd\n", sizeof(f));    // Sizeof a structure array 208
    /*
        f[0].name   |f[0].age| f[0].height |... ...|   f[3].name   |f[3].age| f[3].height |
    */

    return 0;
}