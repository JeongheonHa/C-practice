/* 메모리 레이아웃 */
/* 
<목표> 두 코드 차이 이해하기
// <1> 배열
char arr[] = "Hello, World";
- Hello,World라는 문자열이 arr배열이 대표하는 메모리 공간으로 복사된다
- arr은 배열로서 그 자체로 메모리를 갖고있기 때문에 값을 바꿀 수 있다.

// <2> 포인터
char* str = "Hello, World";
str[0] = 'M';   // error
- 문자열의 첫번째 주소를 가리키고있는 상황
- 문자열 데이터가 담겨있는 메모리 공간을 바꿀 권한은 없다.
- c 언어 컴파일러는 동일한 문자열 리터럴이 프로그램 여러 곳에서 사용될 경우 한 곳에만 저장하고 공유해서 사용 (메모리 절약)
- 여러 포인터가 동일한 문자열을 가리키는 경우가 발생할 경우 문자열 리터럴 값이 변경되는 것을 막는 기능도 한다.
*/

/*
<전체 레이아웃> 
stack [r/w]: 지역변수들이 담긴다. 메모리 크기를 compiler가 미리 예측을 할 수 있는 경우 stack 사용 (속도가 빠르다)

자유공간 (free) : 

heap [r/w]: compiler가 메모리 크기가 얼마가 될지 미리 알 수 없을 경우 사용 heap이라는 메모리 사용

초기화되지 않은 전역/정적 변수들 (BSS(Block Started by Symbol) Segment) [r/w] : 사용자가 초기화하지 않은 값들은 0으로 모두 초기화시킨다.

초기화된 전역/정적 변수들 (DATA Segment) : 사용자가 초기화해놓은 값으로 모두 초기화시킨다.
read write DATA Segment [r/w]
read only DATA Segment [r]

프로그램 코드 (TEXT Segment)[r]: 프로그램이 올라오는 곳 (메모리 크기 고정, 읽기 전용 메모리, 운영체제가 읽기 전용으로 막아놓는다.)

컴파일 : 작성해서 컴파일한 코드 (프로그램) 는 하드디스크에 저장 (컴파일해서 실행파일로 만들어놓은 프로그램은 크기가 변하지 않는다.)
       변수들이 어떤 값으로 초기화되어야할지 미리 알고있다(컴파일할때 이미 결정됨).

//  전역 : 변수들이 프로그램 전체에서 사용할 경우가 많이 있을 때
//  정적 : 프로그램이 작동하는 동안 반복적으로 메모리를 사용해야될 경우
*/


/* array vs pointer differences */

#include <stdio.h>
#include <stdlib.h> // malloc

void test_founction()
{
    int j;
    printf("Stack high \t%llu\n", (unsigned long long)&j);
}

int main()
{
    const char* pt2 = "I am a string!.";
    const char* pt3 = "I am a string!.";
    const char* pt4 = "I am a string!!!!.";
    const char ar1[] = "I am a string!.";
    const char ar2[] = "I am a string!.";
    const char ar3[] = "I am a string!!!.";

    // printf("rodata low \t%llu %llu %llu %llu\n",
    //     (unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
    //     (unsigned long long)"I am a string!.");
    // // 4301963091 4301963091 4301963072 4301963091
    // // pt4가 가리키는 주소 값이 다르다.
    // // c 언어 컴파일러는 동일한 문자열 리터럴이 프로그램 여러 곳에서 사용될 경우 한 곳에만 저장하고 공유해서 사용하기 때문에 같은 주소가 나온다

    // printf("stack high \t%llu %llu %llu %llu\n",
    //     (unsigned long long)ar1, (unsigned long long)ar2, (unsigned long long)pt3,
    //     (unsigned long long)"I am a string!.");
    // // 6098203760 6098203744 4368695069 4368695069
    // // 배열자체가 각각 메모리를 확보하고 각각 문자열 리터럴을 복사해놓는 방식이기 때문에 주소가 모두 다르다.


    // /* local variables */

    // printf("Stack high \t%llu %llu %llu\n",
    //     (unsigned long long)&pt2, (unsigned long long)&pt3, (unsigned long long)&pt4); // 6098203696 6098203688 6098203680
    // // &pt자체는 stack에 저장
    // int i;
    // printf("Stack high \t%llu\n", (unsigned long long)&i);  // 6098203676

    // /* local variable in a function */

    // test_founction();   // 6098203532

    // /* Dynamic allocation 동적 할당 */
    
    // char* p5 = (char*)malloc(sizeof(char) * 100);
    // printf("Heap middle \t%llu\n", (unsigned long long)p5); // 5114980240

    // char* p6 = (char*)malloc(sizeof(char) * 100);
    // printf("Heap middle \t%llu\n", (unsigned long long)p6); // 5114980352

    // ar1++;   // error
    pt2++;  // 가능
    puts(pt2);  //  am a string!. , 증가 연산자로 I 다음부터 출력


    char heart[] = "I love Kelly!";
    const char* head = "I love Helly!";

    for (int i = 0; i < 6; i++)
        putchar(heart[i]);  // putchar : ASCII 코드를 넣어주면 문자 하나를 출력해주는 함수
    putchar('\n');

    for (int i = 0; i < 6; i++)
        putchar(head[i]);  // 포인터를 배열처럼 사용
    putchar('\n');


    // pointer addition
    for (int i = 0; i < 6; i++)
        putchar(*(heart + i));  // 배열을 포인터처럼 산술연산 사용
    putchar('\n');

    for (int i = 0; i < 6; i++)
        putchar(*(head + i));
    putchar('\n');

    while (*(head) != '\0')
        putchar(*(head++));

    head = heart;   // 배열의 이름을 포인터 변수에 대입 가능, 배열의 이름은 포인터와 문법적으로 호환이되게 compiler가 허용
    // heart = head; // error

    // heart는 바꿀 수 없지만, heart의 원소는 바꿀 수 있다.
    heart[7] = 'H';
    *(heart + 7) = 'k';

    putchar('\n');

    char* word = "Goggle";  // 어차피 문자열 리터럴 Google은 TEXT Segment에 있기때문에 바꾸지 못한다. (이런형식은 const 권장)
    // word[2] = 'o';   // runtime error
    puts(word);

    const char *str1 = "When all the lights are low, ...";
    const char *copy;

    copy = str1;    // 주소를 복사, 

    printf("%s %llu %llu\n", str1, (unsigned long long)str1, (unsigned long long)&str1);    // 4298817414 6168081400    (다른 영역에 저장)
    printf("%s %llu %llu\n", copy, (unsigned long long)copy, (unsigned long long)&copy);    // 4298817414 6168081392
    // 포인터 변수 자체는 stack에 저장
    // 문자열 자체는 TEXT Segment에 저장
    
    return 0;
}
