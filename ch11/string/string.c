/* 문자열을 정의하는 방법 */
// 배열은 읽기쓰기가 모두 가능한 메모리에 저장되지만 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장
// c언어에는 문자열을 저장하는 형식이 없어 문자열을 저장할 때 배열이나 포인터 형식으로 저장한다.
// 배열로서 저장할 경우 메모리 사이즈가 1byte, 배열의 길이가 []만큼인 메모리 공간에 문자를 각각 저장 (메모리에 \0포함). (여러번 사용할 경우 매번 메모리에 저장)
// 포인터로서 저장할 경우 문자열 배열의 첫번째 문자의 주소를 저장한다. (여러번 사용할 경우 해당 문자열의 주소로 접근하기 때문에 문자열을 하나만 저장)
// 문자열에서 *(역참조)를 할 경우 단어 하나를 의미
// 문자열을 출력하기 위해서 문자열의 첫번째 주소를 출력 (배열의 경우 배열의 이름, 포인터의 경우 포인터 변수(포인터 변수가 가리키는 것이 문자열의 첫번째 주소이므로))

#include <stdio.h>

#define MESSAGE "A symbolic string contant" // 문자열을 symbolic constant처럼 매크로로 선언하는 방법
#define MAXLENGTH 81    // 문자열에 방해받지않게 넉넉하게 설정

int main()
{
    // <1>
    char words[MAXLENGTH] = "A string in an array"; // 배열로 만드는 방법
    const char* pt1 = "A pointer to a string."; // 문자열에 대한 포인터를 선언하는 방법, 어딘가에 저장되어있을 문자열의 주소만 가져온다.

    puts("Puts() adds a newline at th end:");    // 문자열을 literal로서 바로 출력하는 방법, puts() : 문자열 출력 (\n 자동 출력)
    puts(MESSAGE);
    puts(words);    // warning이 발생하는 경우 : 배열의 길이 만큼 문자열을 초기화 해주지 않았기 때문
    puts(pt1);

    words[3] = 'p'; // t -> p로 교체 (가능)
    puts(words);

    // pt1[8] = 'A';   // runtime error
    
    // <2>
    char greeting[50] = "Hello, and"   " How are" " you"
        " today!";
    // char greeting[50] = "Hello, and How are you today!"; 과 동일

    puts(greeting);

    printf("\" To be, or not to be\" Hamlet said.\n");  // " To be, or not to be" Hamlet said.

    printf("%s, %p, %c\n", "We", "are", *"excellent programmers");  
    // 문자열을 배열에 넣어서 초기화 할 수 있다면 "are"의 주소는 첫 글자 a가 저장된 주소
    // " "안의 문자열이 저장된 메모리에서 주소는 첫번째 문자의 주소이므로 첫번째 주소를 indirection할 경우 첫번쨰 문자라는 뜻

    // <3>
    const char m1[15] = "Love you!";    // 나머지도 0으로 초기화

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m1[i]);  // 76 111 118 101 32 121 111 117 33 0 0 0 0 0 0
    printf("\n");

    const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };  // 문자열이 아닌 문자의 배열 초기화
    const char m3[] = "Love you, too!";

    // <4>
    int n = 8;
    char cookies[1] = {'A', };
    char cakes[2 + 5] = {'A', };
    char pies[2 * sizeof(long double) + 1] = {'A', };
    char crumbs[n]; // VLA를 지원하는 프로그램에서는 가능
    
    // <5>
    char truth[10] = "Truths is ";
    if (truth == &truth[0]) puts("true!");
    if (*truth == 'T') puts("true!");
    if (*(truth + 1) == truth[1]) puts("true!");
    if (truth[1] == 'r') puts("true!"); // 배열로서의 성질을 가지고있기때문에 char타입의 원소를 indexing해서 값을 바꾸거나 비교할 수 있다.

    return 0;
}