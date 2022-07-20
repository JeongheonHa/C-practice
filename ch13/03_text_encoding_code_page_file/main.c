/* 텍스트 인코딩과 코드 페이지 */
// 디코딩의 방식의 따라 console에 출력되는 참고하는 표의 방식이 다르다.
// 원본.txt를 저장할 때 인코딩 방식과를 c 프로그램에서 디코딩하는 방식이 일치해야한다.
// 컴퓨터는 원본을 이진수로 읽어드리고 그 이진수를 디코딩하는 과정에서 표(코드 페이지)를 잘못 참고할 경우 console창에 이상한 값이 나온다.
// 다시 사본으로 저장할 때는 어차피 데이터를 저장해서 인코딩을 하는 것이기 때문에 상관없다.

#include <stdio.h>
#include <stdlib.h>
// #include <windows.h> // SetConsolOutputCP()

int main()
{
    // const UNIT default_cp = GetConsolOutputCP(); // 코드 페이지
    // printf("%u\n", default_cp);

    int ch;
    FILE* fr ,* fw;   

    const char* in_filename = "원본.txt";
    const char* out_filename = "사본.txt";

    unsigned long count = 0;

    if ((fr = fopen(in_filename, "r")) == NULL) 
    {
        printf("Can't open %s\n", in_filename);
        exit(EXIT_FAILURE);
    }

    if ((fw = fopen(out_filename, "w")) == NULL) 
    {
        printf("Can't open %s\n", out_filename);
        exit(EXIT_FAILURE);
    }

    // SetConsoleOutputCP(CP_UTF8); // UTF-8 mode로 바꿔준다.

    while ((ch = fgetc(fr)) != EOF) 
                                   
    {
        fputc(ch, stdout); 
      
        fputc(ch, fw);

        count++;
    }

    fclose(fr);
    fclose(fw);
    
    // SetConsoleOutputCP(default_cp);  // 다시 기본 모드로 돌아가서 출력할 경우 프로그램 안에 있는 한글이 깨지지 않는다.

    printf("File %s has %lu character\n", in_filename, count);
    printf("Copied to %s\n", out_filename);

    printf("한글 출력 확인");

    return 0;
}   