/* 문자열을 출력하는 방법들 */

#include <stdio.h>

#define TEST "A string from #define."

void custom_put(const char* str); 
int custom_put2(const char* str);

int main()
{
// char str[60] = "String array initialized";
// const char* ptr = "A pointer initialized";

// puts("String without \\n");
// puts("END");
// puts(TEST);
// puts(TEST + 5); // ing from #define. , 문자열 배열의 첫번째 주소에서 + 5
// puts(&str[3]);  // ing array initialized
// // puts(str[3]); // error
// puts(ptr + 3);  // ointer initialized


/* \0이 없을 경우 */
// char str[] = { 'H', 'I', '!' };     //string이 아닌 각각의 배열로서 문자를 넣을 경우 \0이 없다. (" "를 이용할 경우에는 자동으로 \0이 생성)
// puts(str);  // error, \0을 만나 종료해야하는데 종료하지 못한다.

/* puts() and fputs() */

// puts()
// char line[100];
// while (gets(line))  // while (gets(line) != NULL)이라는 뜻
//     puts(line);

// fputs()
// char line[100];
// while (fgets(line, 81, stdin))
//     fputs(line, stdout);    // 개수가 필요하지는 않다.

/* printf */

// char str[] = "Just do it, do it!";
// printf("%s\n", str);
// puts(str);

char input[100] = "";
int ret = scanf("%10s", input); // 입력 : "Just do it, do it!\n", 10개만 읽는다. (빈칸을 만나면 stop)
printf("%s\n", input);  // 출력 : "Just", scanf()함수는 빈칸을 만나면 더 이상 읽지 않는다.
ret = scanf("%10s", input); // 버퍼에 남아있는 문자열을 읽는다.
printf("%s\n", input);  // 출력 : do

/* custom function */

// custom_put("Just ");
// custom_put("Do it!");

// printf("%d\n", custom_put2("12345"));

// return 0;
}

// void custom_put(const char* str)
// {
//     while (*str != '\0')    // while(*str) 과 같은 코드 (스타일 차이)
//         putchar(*str++);
// }

// int custom_put2(const char* str)
// {
//     int count = 0;
//     while (*str)
//     {
//         putchar(*str++);
//         count++;
//     }
//     putchar('\n');

//     return count;
// }