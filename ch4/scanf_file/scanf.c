# include <stdio.h>
# include <inttypes.h>

int main()
{
    /* multiple inputs with blank separators */
    /*
    int i;
    float f;
    char str[30];
    scanf("%d %f %s", &i, &f, str);     // 문자열 배열의 경우 &을 붙이지 않는다.
    printf("%d %f %s\n", i, f, str);
    */
   
    /* character */
    /*
    char c;
    scanf("%c", &c);   // 빈칸 입력
    printf("%i\n", c);  // 32(빈칸의 아스키코드), 빈칸도 문자로 인식
    */

    /* Unsigned as signed */
    /*
    unsigned i;
    scanf("%i", &i);    // unsigned인 i를 받을 때 signed로 받고(%i) 받은걸 unsigned 메모리에 저장을 해놨다가(&i) 다시 signed로 꺼내기 때문에 sigend가 나온다.
    printf("%i\n", i);  // 이렇게 코딩을 하는것은 좋지않다.
    */
    
    /* Unsigned as unsigned */
    /*
    unsigned i2;
    scanf("%u", &i2);
    printf("%u\n", i2);
    */

    /* floating point numbers */
    /*
    double d = 0.0;
    scanf("%lf", &d);   // scanf에서는 double의 형식지정자로 lf를 사용해야한다. 
    printf("%f\n", d);  // f 사용
    */

    /* Width */
    /*
    char str[30];
    scanf("%5s", str);  // 문자개수 5개로 지정
    printf("%s\n", str);
    */

    /* h modifier */
    /*
    char i;
    scanf("%hhd", &i);  // char타입 -> hhd 사용
    printf("%i\n", i);
    */

    /* integer with characters */
    /*
    int i;
    scanf("%i", &i);    // try 111abc
    printf("%i\n", i);  // 111, 문자열 abc는 짤리고 111만 출력
    */

    /* j modifier */
    /*
    intmax_t i;     // 가장 큰 정수형이라는 portable 타입으로 i 변수 설정
    scanf("%ji", &i);   // %ji 사용
    printf("%ji", i);
    */

    /* Regular characters */
    /*
    int a, b;
    scanf("%d,%d", &a, &b);     // 이전까지는 구분할때 빈칸을 사용했지만 scanf에 ,를 사용함으로서 구분할때 ,를 사용하도록 지정
                                // ,뿐만아니라 다른 기호,문자들도 가능하다.
    printf("%d %d\n", a, b);
    */

    /* return value of scanf */
    // scanf함수의 return값은 입력한 개수이다.
    /*
    int a, b;
    int i = scanf("%d%d", &a, &b);
    printf("%d\n", i);
    */

    /* * modifier for printf() */
    /*
    int i = 123;
    int width = 0;
    printf("Input width : ");
    scanf("%d", &width);    // try 5
    printf("%*d\n", width, i);  //   123, 빈칸 2개 + 123 출력
    */

    /* * modifier for scanf() */
    // scanf에서 %*d는 무시한다.
    int i;
    scanf("%*d%*d%d", &i);  // scanf에서 *을 사용할 경우 3가지 모두 입력은 하지만 출력은 *가 없는 %d만 출력한다.
    printf("the third input is %d\n", i);

    return 0;
}