/* 명령줄 인수 */
// 사용자가 프로그램을 실행시킬때 인자를 넣어줄 수 있다. (실행파일을 열어 인자를 넣어준다.)
// 실행 시킬때 실행파일뒤에 붙여주는 arguement들을 parameter로 보내준다.
// c/c++로 만든 실행파일을 다른 스크립팅 언어를 이용해서 반복해서 실행할 경우 유용
// #include <stdio.h>

// int main(int argc, char* argv[]) // argv[]에 담긴 문자열이 몇개인지 argc에 담겨서 들어온다.
// {
//     int count;

//     printf("The command line has %d arguments: \n", argc);

//     for (count = 0; count < argc; count++)
//         printf("Arg %d ; %s\n", count, argv[count]);
//     printf("\n");

//     return 0;
// }

/* 문자열을 숫자로 바꾸는 방법들 */

#include <stdio.h>

int main(int argc, char * argv[])
{
    /*
        string to integer, double, long
        atoi(), atof(), atol()
    */

    // if (argc < 3)
    //     printf("Wrong Usage of %s\n", argv[0]); // argv[0] : 실행파일 자체의 이름
    // else
    // {
    //     // <ex1>

    //     int times = atoi(argv[1]);  // 문자를 숫자로 바꾸고 숫자를 times 변수에 대입
    //     // atof(), atol()

    //     for (int i = 0; i < times; i++)
    //         puts(argv[2]);
        
    //     // <ex2>
    //     printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
    // }

    /*
        string to long, unsigned long, double
        strtol(), strtoul(), strtod()

        strtod()는 converts base 10 only (strtoi와 유사), 나머지는 base가 자유롭다.
    */

    // char str1[] = "-1024Hello";
    // char* end;
    // long l = strtol(str1, &end, 10);    // 10진수
    // printf("%s %ld %s %d\n", str1, l, end, (int)*end);

    // char str2[] = "10FFHello";
    // l = strtol(str2, &end, 16);     // 16진수
    // printf("%s %ld %s %d\n", str2, l, end, (int)*end);

    /* 
        Numbers to strings
        Use sprintf() instead of itoa(), ftoa()
    */
    // _itoa는 많이 사용하지않는다. 대신 sprintf()함수를 선호
    char temp[100];
    puts(_itoa(10, temp, 16));  // 10을 16진수로 표현

    sprintf(temp, "%x", 10);    // 10을 16진수로 표현
    puts(temp);

    return 0;
}

