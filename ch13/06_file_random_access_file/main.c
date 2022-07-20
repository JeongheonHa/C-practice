/* 파일 임의 접근 */

// #include <stdio.h>
// #include <stdlib.h>

// /*
//     ABCDEFG ...
//     current position 0 and read -> A
//     current position 1 and read -> B
// */

// int main()
// {
//     int ch;
//     long cur;

//     FILE* fp = fopen("test.txt", "r");

//     cur = ftell(fp);    // ftell()함수는 현재의 위치를 반환한다.
//     printf("ftell() = %ld\n", cur);     // ftell() = 0

//     /* SEEK_SET */
//     fseek(fp, 2L, SEEK_SET);            // 시작점(SEEK_SET)으로부터 2byte 떨어진 곳으로 이동한다.
//     cur = ftell(fp);
//     printf("ftell() =  %ld\n", cur);    // ftell() =  2
//     ch = fgetc(fp);                     // 파일의 포인터로부터 문자를 하나읽고 반환한다.
//     printf("%d %c\n", ch, ch);          // 67 C
//     cur = ftell(fp);
//     printf("ftell() = %ld\n", cur);     // ftell() = 3

//     /* SEEK_CUR */
//     fseek(fp, -2L, SEEK_CUR);           // 현재위치(SEEK_CUR)로부터 -2byte 떨어진 곳으로 이동한다.
//     cur = ftell(fp);
//     printf("ftell() = %ld\n", cur);     // ftell() = 1
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);          // 66 B

//     /* SEEK_END */
//     fseek(fp, 0L, SEEK_END);            // 끝에서부터 찾는다.
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);          // -1

//     fseek(fp, -1L, SEEK_END);
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);          // 90 Z

//     fseek(fp, -2L, SEEK_END);       
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);          // 89 Y

//     /* fsetpos(), fgetpos() */

//     fpos_t pt;
//     pt = 10;
//     fsetpos(fp, &pt);           // fseek과 비슷
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);  // 75 K
//     fgetpos(fp, &pt);           // ftell과 비슷
//     printf("%lld\n", pt);       // 11, fpost_t에 대한 형식지정자가 따로 존재하지 않는다. (long long 타입을 사용)

//     return 0;
// }

/* random binary */

#include <stdio.h>

int main()
{
    // make a test binary file
    {
        FILE* fp = fopen("binary", "wb");
        for (int i = 0; i < 100; ++i)
        {
            double d = i * 1.11;
            fwrite(&d, sizeof(double), 1, fp);
        }
        fclose(fp);
    }

    // read
    FILE* fp = fopen("binary", "rb");
    long cur;
    double d;

    cur = ftell(fp);
    printf("Before reading %ld\n", cur);    // Before reading 0

    fread(&d, sizeof(double), 1, fp);

    cur = ftell(fp);
    printf("After reading %ld\n", cur);     // After reading 8

    printf("%f\n",d);                       // 0.000000

    fread(&d, sizeof(double), 1, fp);
    printf("%f\n",d);                       // 1.110000

    cur = ftell(fp);
    printf("After reading %ld\n", cur);     // After reading 16

    fseek(fp, 32L, SEEK_SET);
    fread(&d, sizeof(double), 1, fp);
    printf("%f\n", d);                      // 4.440000

    fclose(fp);

    return 0;
}
