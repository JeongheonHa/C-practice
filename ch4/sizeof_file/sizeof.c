/* sizeof */

#include <stdio.h>

int main()
{
    /* sizeof basic types */
    /*
    int a = 0;
    unsigned int int_size1 = sizeof a;  // 3개 다 같은 의미
    unsigned int int_size2 = sizeof(int);
    unsigned int int_size3 = sizeof(a);

    size_t int_size4 = sizeof(a);   // unsigned int = size_t, 다른 시스템에서 sizeof의 값을 구하는 자료형이 unsigned int가 아닐 경우 사용
    size_t float_size = sizeof(float);

    printf("Size of int type is %u bytes.\n", int_size1);
    printf("Size of int type is %zu bytes.\n", int_size4);
    printf("Size of float type is %zu bytes.\n", float_size);

    return 0;
    */

    /* sizeof arrays */
    /* 
    int int_arr[30];     // int타입의 연결되어 있는 공간 30개를 가져오기위해 int_arr 배열을 초기화, 120byte공간의 대표 주소이지만 사용할때만 바뀐다, compile할때 결정
    int *int_ptr = NULL;     // 주소를 적는 종이지 같은 느낌
    int_ptr = (int*)malloc(sizeof(int) * 30);    // 메모리 공간을 얼마나 할당 받을지 run time에 결정

    printf("Size of array = %zu bytes\n", sizeof(int_arr));      // 120byte
    printf("Size of pointer = %zu bytes\n", sizeof(int_ptr));    // run time에 결정나기 때문에 그냥 메모지의 사이즈인 4byte를 출력
   
    return 0;
    */

    /* sizeof character array */

    char c = 'a';
    char string[10];

    size_t char_size = sizeof(char);
    size_t str_size = sizeof(string);   // maximally 9 character + '\0'
                                        // c언어에서는 문자를 저장할 때 마지막에 '\0'(null character)하나를 저장 (마침표 역할)

    printf("Size of char type is %zu bytes.\n", char_size);     // 1byte
    printf("Size of string type is %zu bytes.\n", str_size);    // 10byte

    return 0;

}