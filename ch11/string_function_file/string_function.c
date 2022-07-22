/* 다양한 문자열 함수들 */

#include <stdio.h>
#include <string.h>

void fit_str(char* str, unsigned int size);

int main()
{
    /* strlen() */
    // 문자열의 길이 반환

    char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %lu\n", strlen(msg));    // 12
    fit_str(msg,4);
    puts(msg);
    printf("Length %lu\n", strlen(msg));    // 4


    /* strcat() and strncat() */
    // string concatenation (문자열 덧붙이기)

    char str1[100] = "First string";    // 첫번째 문자열의 메모리 공간이 충분해야한다. 
    char str2[] = "Second string";

    // <1>
    // strcat(str1, ", ");
    // strcat(str1, str2);
    // puts(str1); // First string, Second string

    // <2>
    // strncat(str1, str2, 2);
    // puts(str1); // First stringSe, 2글자만큼만 덧붙인다.

    // <과제>
    // strcat()함수 만들어보기

    /* strcmp() and strncmp() */
    // compare strings (not characters)
    // 같으면 0
    // 아스키코드로 비교했을 때 앞에있는 문자열이 더 빠를(낮을) 경우 -1, 더 느릴(클) 경우 1

    // printf("%d\n", strcmp("A", "A"));   // 0
    // printf("%d\n", strcmp("A", "B"));   // -1
    // printf("%d\n", strcmp("B", "A"));   // 1
    // printf("%d\n", strcmp("Hello", "Hello"));   // 0
    // printf("%d\n", strcmp("Banana", "Bananas"));    // -1
    // printf("%d\n", strcmp("Bananas", "Banana"));    // 1
    // printf("%d\n", strncmp("Bananas", "Banana", 6));    // 0, 앞에서부터 6글자만 비교를 한다.

    // <과제>
    // strcmp함수 만들어보기

    /* strcpy() and strncpy() */
    // 포인터 뿐만아니라 문자열을 한글자씩 돌면서 복사를 한다.
    // \0 (NULL character)를 복사하지 않는다. (메모리 자체를 복사하는 용도로 종종 사용이되기 때문)

    // char dest[100] = "";
    // char source[] = "Start programming!";
    // dest = source;  // error, 배열의 주소를 바꾸는 것이기 때문에 안된다.
    // dest = "Start something";   // error

    // strcpy(dest, source);   // source를 destination에 복사

    // strncpy(dest, source, 5);   // Start 복사 (\0은 추가되지 않는다. 온전히 5글자만 복사)

    // strcpy(dest, source + 6);   // 포인터 연산 이용 (복사 시작위치를 바꿀 수 있다)

    // strcpy(dest, source);
    // strcpy(dest + 6, "coding!");    // Start coding!, 6번째 글자 다음부터 복사

    // puts(dest);

    /* sprintf() */
    // 연속되는 파일을 자동으로 생성할때 파일의 이름을 문자열로 만들어 유용하게 사용
    // ex) capture00000.png, capture00001.png ...\

    char str[100] = "";
    int i = 123;
    double d = 3.14;
    sprintf(str, "%05d.png %f", i, d);  // printf()를 str문자열에 해준다.
    puts(str);  // 00123.png 3.140000

    /* 이 밖의 함수들 */
    printf("%s\n", strchr("Hello, World", 'W'));    // World, 'W'글자가 시작하는 문자열의 포인터를 리턴 -> 포인터를 스트링으로 출력
    printf("%s\n", strpbrk("Hello, World", "ABCDE"));   // (null), ABCDE 중에서 하나로 시작되는 문자를 찾아 포인터 리턴
    printf("%s\n", strpbrk("Hello, World", "abcde"));    // ello, World, abcde 중에서 하나로 시작되는 문자를 찾아 포인터 리턴
    printf("%s\n", strrchr("Hello, World, Hello, World", 'l')); // ld , 'l' 글자가 나타나는 가장 마지막 포인터를 리턴
    printf("%s\n", strstr("Hello, World", "wor"));  // (null), 문자열 끼리 비교
    printf("%s\n", strstr("Hello, World", "Wor"));  // World , 문자열 끼리 비교해서 일치하는 문자열의 포인터 리턴

    return 0;
}

void fit_str(char* str, unsigned int size)
{
    if (strlen(str) > size)
        str[size] = '\0';
}