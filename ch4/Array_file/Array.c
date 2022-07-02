/* 문자 배열 */
// 배열 : 같은 데이터 타입의 저장 공간을 여러개 확보하는 것

#include <stdio.h>

int main()
{
    /* <ex1> */
    /*
    // char fruit_name;    // 오직 1개의 문자만을 저장
    char fruit_name[40];    // char 타입 40개의 메모리 공간의 대표 주소 1개만 알려준다.
    // char 타입 40개가 나란히 배열되어있는 메모리 공간을 대표하는 주소가 fruit_name
    
    printf("What is your favorite fruit?\n");

    scanf("%s", fruit_name);   // 형식 지정자 %s (string)을 사용 
    // &은 주소를 불러오기위해 사용하지만 fruit_name자체가 대표 주소이기 때문에 &을 안붙인다.

    printf("You like %s\n", fruit_name);

    return 0;
    */

    /* <ex2> */
    /*
    char c = 'a';
    char str1[10] = "Hello";         // "Hello\0"와 같은 의미
    char str2[10] = { 'H' , 'i'};    // 두가지 모두 같은 표현 방식

    printf("%c\n", c);
    printf("%s\n", str1);    // 문자열을 출력할 때 str1 배열의 문자를 하나하나 출력하다가 '\0'를 만날 경우 출력 stop 
    printf("%s\n", str2);
    
    printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]);  // 72 105 0 0 0
    
    return 0;
    */

    /* <ex3> */
    // '\0'(null character)가 문자열 중간에 들어갈 경우

    char str3[20] = "Hello, \0World";

    printf("%s\n", str3);    // Hello, null을 만나 출력을 멈춘다.
    printf("%c\n", str3[10]);   // r , 메모리 공간에서 사라진 것이 아니다.
    return 0;
}


/* 숫자의 배열 */
/*
#include <stdio.h>

int main()
{
    int a = 1;
    int int_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf(" %i %i %i\n", int_arr[0], int_arr[1], int_arr[5]);

    // printf("%i\n", int_arr[10]);     // 메모리 저장공간 범위 밖의 메모리를 불러올때 error 발생

    return 0;
}
*/