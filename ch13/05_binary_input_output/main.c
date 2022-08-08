/* 바이너리 파일 입출력 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        fopen() mode string for binary io
        - "rb", "wb", "ab"
        - "rb+", "r+b" (앞에 붙든 뒤에 붙든 같은 의미)
        - "wb+", "w+b"
        - "ab+", "a+b"

        c11에서는 'x' mode 추가
        'x' mode fails if the file exists, instead of overwriting it.
        - "wx", "wbx", "w+x", "wb+x", "w+bx"
    */

    // writing example
    {
        FILE* fp = fopen("binary_file", "wb");  // ms word, 아래 한글, .docx 등등 대부분 binary file의 형식이다.

        double d = 1.0 / 3.0;
        int n = 123;
        int * parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);
        for (int n = 0; n < 123; ++n)
            *(parr + n) = n * 2;
        
        fwrite(&d, sizeof(d), 1, fp);   // 주소, 사이즈, 사이즈 몇 개, 파일의 포인터
        fwrite(&n, sizeof(n), 1, fp);
        fwrite(parr, sizeof(int), n, fp);   // 배열의 경우

        fclose(fp);
        free(parr);
    }

    // reading example (feof(), ferror())
    // binary file이 어떤 형식으로 저장되어 있는 것인지 알고있어야만 해독을 할 수 있다.
    {
        FILE* fp = fopen("binary_file", "rb");
        double d;
        int n = 0;
        fread(&d, sizeof(d), 1, fp);
        fread(&n, sizeof(n), 1, fp);

        int* parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);

        fread(parr, sizeof(int), n, fp);    // parr에 int만큼의 size n개를 읽어드린다.

        printf("feof = %d\n", feof(fp));    // 0, feof() : EOF를 만났는가? 만나지 않았다면 0 반환, 만났다면 1 반환

        printf("%f\n", d);  // 0.333333
        printf("%d\n", n);  // 123
        for (int i = 0; i < n; ++i)
            printf("%d ", *(parr + i));
        printf("\n");

        printf("feof = %d\n", feof(fp));        // 0

        fread(&n, sizeof(n), 1, fp);            // read one more toward EOF (EOF를 만난다)

        printf("feof = %d\n", feof(fp));        // 1, returns non-zero at EOF
        printf("ferror = %d\n", ferror(fp));    // 0, return 0 (ok), ferror() : 파일 스트림이 읽는 과정에서 에러가 있는지 없는지를 확인
                                                // 에러가 없다면 0 반환, 있다면 1 반환

        fwrite(&n, sizeof(n), 1, fp);           // rb mode에서 write를 할 수 없는 상태

        printf("ferror = %d\n", ferror(fp));    // 1, fwrite함수로 강제로 쓰려고 해서 먼가 error가 있다는 것을 알려주고자 1을 반환한다.

        fclose(fp);

        return 0;
    }

}