/* 파일 읽기 */
// 파일을 읽는 방법은 크게 binary vs ASCII 코드
#include <stdio.h>
#include <stdlib.h> // exit(1)

int main()
{
    int c;
    FILE *file = NULL;  // *file : file이 pointer 변수, file을 읽어드리는 stream을 다룰 수 있는 어떤 정보가 변수에 담겨있다.
    char file_name[] = "my_first.rtf";

    file = fopen(file_name, "r");   // fopen : file의 stream을 열어준다(통로를 열어준다). read / write
                                    // file_name파일의 읽어드릴 수 있는 통로를 열어 file에 대입
    if (file == NULL)   // stream을 여는 것을 실패한 경우
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    while ((c = getc(file)) != EOF) // file stream으로부터 문자를 읽어드리고 EOF를 만날 때까지 계속 하나씩 출력
        putchar(c);
    fclose(file);   // file의 stream을 닫아준다.

    return 0;
}