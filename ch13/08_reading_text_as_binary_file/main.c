/* 테스트 파일 바이너리 처럼 읽기 */

#include <stdio.h>

int main()
{
    FILE* fp = fopen("test.txt", "rb");

    unsigned char ch;

    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)    // fread함수의 반환 값은 읽어드린 데이터의 양이다.
    {
        printf("%hhu %c\n", ch, ch);    // 알파벳이나 숫자를 표현할 때는 1byte를 사용하고 한글을 사용할 때는 3byte씩 묵어서 사용한다는 것을 알 수 있다.
    }

    fclose(fp);

    return 0;
}