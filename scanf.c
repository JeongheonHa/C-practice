// #define _CRT_SECURE_NO_WARNINGS (VISUAL STUDIO에서 scanf 사용할시 error발생)
// 해결방법 : properties -> preprocessor -> configuration(active(debug)) -> ;_CRT_SECURE_NO_WARNINGS 붙여넣기
#include <stdio.h>

int main()
{
    int i = 0, j = 0, sum = 0;   // = 0을 사용하는 이유 : 변수를 초기화 시키기위해
    
    printf("Input Two integers\n");
    scanf("%d%d" , &i, &j);     // & : ampersand, console 창에서 사용자의 입력을 받을때 사용
                                // &i는 scanf함수에게 변수의 주소를 알려준다. -> scanf함수가 주소를 통해 메모리에 직접 접근해서 값을 바꿔버린다.
                                // (즉, int i = 0라고 변수 지정을 했어도 scanf함수가 값을 바꾼다)
                                // c문법에서는 함수의 출력이 1개밖에 안된다.
    sum = i + j;
    printf("%d + %d = %d\n", i, j, sum);    // %d의 개수와 변수의 개수가 같아야한다.

    return 0;
}
