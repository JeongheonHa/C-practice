/* 기타 입출력 함수들 */

#include <stdio.h>

int main()
{
    FILE* fp;
    int ch;

    /* ungetc() */
    // 한 글자를 읽고 다시 버퍼에 집어넣는다.

    // fp = fopen("input.txt", "r");

    // ch = fgetc(fp);
    // fputc(ch, stdout);  // "

    // ungetc(ch, fp);     // 읽어드린 문자를 다시 버퍼에 넣는다.
    // // ungetc((int)'A', fp) // 버퍼에 A를 넣는다.
    // ch = fgetc(fp);
    // fputc(ch, stdout);  // "

    // ch = fgetc(fp);
    // fputc(ch, stdout);  // I

    // fclose(fp);

    /* setvbuf(fp) */
    // buffer의 설정을 바꿔줄 수 있다.

    fp = fopen("input.txt", "r");

    char str[32] = {'\0', }; // 배열 선언

    setvbuf(fp, str, _IOFBF, sizeof(str));    // str이라는 배열의 공간을 buffer로 사용하라는 뜻 (_IOLBF, _IOFBF, _IONBF)
                                                    // _IOLBF : 라인(Line) 하나씩을 꺼내서 버퍼에 저장
                                                    // _IOFBF : 내용 전체(Full)를 꺼내서 버퍼에 저장
                                                    // _IONBF : 버퍼를 생성하지 않는다. (No)
    ch = fgetc(fp); // read just only a single character

    // dump buffer
    for (int i = 0; i < sizeof(str); ++i)
            printf("%c", str[i]);    // "I choose a lazy person to do a, 한글자만 읽었는데 버퍼에 내용이 다 찼다. 
                                        // 해당 파일의 내용을 모두 읽을 것으로 예상이 되면 미리 버퍼에 내용을 모두 채워 놓는다.
                                        // 파일에서 버퍼로 옮기는 것은 느리기때문에 한번에 많은 양을 가져오고 버퍼에서 글자를 
                                        // 가져오는 것은 비교적 빠르기때문이다 (c언어는 효울성을 중요시 하기 때문)
        printf("\n");

    fclose(fp);

    /* fflush() */
    // buffer에 쌓여있는 데이터들을 싹 비워내라
    // ex) writing할 데이터가 너무 많아 os와 c프로그램이 파일에 완벽하게 출력을 하지 못할 경우 fflush()를 사용하여 반드시 모두 출력하게 할 수 있다.
    //  (모든 경우가 다 가능한 것은 아니다.)

    // Writing a large amount of data
    // fflush(fp);

    return 0;
}