/* 전처리를 준비하는 번역 단계 */

#include <stdio.h>

int main()
{
    /*
        Program written in C

        Translating
        Preprocessing
        Compiling
        Linking

        Executable
        // 번역과정을 전 처리기와 따로 분류하는 개념도 있다.
    */

    /*
        International characters

        내부적으로 컴파일러가 이해할 수 있는 문자 집합으로 번역
    */

    puts("안녕하세요.\n");

    /*
        Trigraph Sequences
        - Some keyboards don't provide all the symbols used in C.
        - Three-character sequences

        Trigraph        Replacement
        ??=             #
        ??/             \
        ??'             ^
        .               .
        .               .
        .               .
    */

    /*
        Digraphs
        - Two-character sequences
    */

    /* Two physical lines vs One logical line */
    printf("This is a very very very very very very \
very very very very very very long long long long long line.\n");

    /*
        Tokens
        - Groups separated from eash other by spaces, tabs, or line breaks
        Whitespace characters -> a single space
        사용자가 입력한 코드를 token 단위로 쪼갠다.
    */

    int/* a variable to count a number*/n = 1;  // 주석을 빈칸 하나로 인식
    // int n = 1;                               // 이런 형식

    return 0;
}