/* 텍스트 파일 입출력 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) // main에서 명령줄 인수를 받아오고 있는 중
{
    int ch;
    FILE* fr;   // 파일을 처리할 때 필요한 데이터의 묶음에 대한 포인터 (데이터의 묶음 : 구조체)

    /*
        typedef struct _iobuf (데이터의 묶음을 FILE이라는 자료형이 있는 것 처럼 사용)
        {
            char*   _ptr;
            int _cnt;
            char*   _base;
            int _flag;
            int _file;
            int _charbuf;
            int -bufsiz;
            char*   _tmpname;
        } FILE;
    */

    unsigned long count = 0;

    if (argc != 2)  // c 프로그램의 명령줄 인수 사용의 일반적인 방식
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fr = fopen(argv[1], "r")) == NULL) // stream을 열지 못했다는 뜻, fopen은 파일의 포인터를 리턴한다. (open a text file for reading)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*
        fopen mode strings for text files (" ")
        - r : reading
        - w : creating-and-writing or over-writing (파일이 없다면 만들고 쓰고, 있을 경우 기존내용 모두 지우고 덮어쓰기)
        - a : appending or creating-and-writing (파일이 없다면 만들고 쓰고, 있을 경우 덧붙이기)
        - r+ : both reading and writing
        - w+ : reading and writing, over-writing or creating
        - a+ : reading and writing, appending or creating
    */

    while ((ch = fgetc(fr)) != EOF) // fgetc() : fr이라는 파일의 포인터로부터 문자를 한 글자씩 받아온다. (int를 반환)
                                    // getc()와 매우 유사 (fgetc()를 사용하는 것이 보다 안정적이다.)
    {
        fputc(ch, stdout);  // stdout대신 stderr를 넣을 경우 stderr stream을 통해 출력 (redirection), (fputc를 사용하는 것이 보다 안정적이다.)
        // putc(ch, stdout);    // same as putchar(ch);

        count++;
    }

    fclose(fr); // file stream을 다 사용한 경우 반드시 닫아줘야한다. (버퍼에 아직 처리하지 못한 데이터가 남아있는 경우 처리해줄 수 있디)

    printf("File %s has %lu character\n", argv[1], count);

    return 0;
}   