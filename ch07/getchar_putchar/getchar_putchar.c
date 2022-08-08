/* 표준 입출력 함수들 */
// getchar, putchar은 한 글자씩 처리한다, getchar에서 입력받을 때 여러문자 입력 가능
// getchar에서 여러 문자를 입력받기 -> 입력받은 문자열 buffer에 임시 저장 -> getchar에서 입력받은 문자(buffer에 임시저장된) 하나씩 ch변수에 저장
// -> ch변수에서 putchar로 한글자씩 출력 

#include <stdio.h>  // getchar, putchar 포함되어있음

int main()
{
    /* <ex1> */
    /*
    char ch;

    // ch = getchar(); // getchar : 문자 받기, 
    // putchar(ch); // putchar : 문자 출력

    while ((ch = getchar()) != '\n')  // 엔터를 칠 경우 while문을 종료하겠다는 의미, ch = getchar()의 경우 우선순위가 낮기 때문에 ()사용
    {
        putchar(ch);    // buffer라는 공간에 임시 저장된 문자열을 하나씩 출력

        // ch = getchar();
    }

    putchar(ch);    // ch = '\n'
    */

    /* <ex2> */
    /*
    // f, F -> X

    char ch;

    while ((ch = getchar()) != '\n')
    {
        if( ch == 'f' || ch == 'F') // || : 또는, 둘 중 하나라도 만족하면
            ch = 'X';

        putchar(ch);
    }

    putchar(ch);
    */

    /* <ex3> */
    /*
    // 숫자 -> *

    char ch;

    while ((ch = getchar()) != '\n')
    {
        // <1>
        // for (int i = '0'; i <= '9'; ++i)    // getchar이 문자로 받기때문에 ch에 문자의 아스키코드 대입
        //    if (ch == i)    // ch와 i를 비교하기 위해서는 i를 아스키코드로 지정해줘야함.
        //      ch = '*;
        // putchar(ch);

        // <2> *선호*
        if (ch >= '0' && ch <= '9') // && : and, 두 조건 모두 만족하면
            ch = '*';

        putchar(ch);
    }

    putchar(ch);
    */

    /* <ex4> */
    // 소문자 -> 대문자, 대문자 -> 소문자

    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'a' && ch <='z')
            ch -= 'a' - 'A';    // 'a' : 97, 'A' : 65 아스키코드 차를 이용
        else if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';
            
        putchar(ch);
    }

    putchar(ch);

    return 0;
}

/* ctypes.h */
// #include <ctypes.h>
// https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
// 여러기능의 함수들