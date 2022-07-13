/* 문자열을 정의하는 방법 */

#include <stdio.h>

#define MESSAGE "A symbolic string contant" // 문자열을 symbolic constant처럼 매크로로 선언하는 방법
#define MAXLENGTH 81

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