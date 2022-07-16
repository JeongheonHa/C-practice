/* 객체와 식별자, L-value와 R-value */

#include <stdio.h>

int main()
{
    /*
        object : 값을 저장할 수 있는 메모리 블록
        identifier : 변수, 함수, 매크로 등등의 이름
    */

    int var_name = 3;
    // 변수의 이름을 통해 접근해서 메모리 공간안에 3을 저장할때 메모리 공간을 object, 변수 이름을 identifier

    int* pt = &var_name;    // pt는 identifier이다.
    *pt = 1;    // *pt는 identifier가 아니다. *pt는 object를 지목한다는 뜻.

    int arr[100];   // arr은 identifier이지만 object는 아니다. 배열의 첫번째 원소의 주소인 arr은 메모리 공간을 갖는 object가 아니다. 
    arr[0] = 7; // arr[0](expression)을 통해서 메모리 공간을 접근할 수 있기 때문에 arr[0]은 object이다.

    /*
        lvalue is an expression 'referring' to an object.

        L-value : left side of an assignment
        R-value : right side, variable, constant, expressions
    */

    var_name = 3;   // modifiable lvalue, var_name이 refering 해주는 메모리 공간에 3이라는 값을 복사해준다.)
    int temp = var_name;    // rvalue도 가능, rvalue역할을 할때는 사실상 값만 옮겨준다.
    temp = 1 + 2;   // expression (rvalue)

    pt = &var_name;
    int* ptr = arr;
    *pt = 7;    // pt is not an identifier but an modifiable lavlue expression

    int *ptr2 = arr + 2 * var_name; // address rvalue
    *(arr + 2 * var_name) = 456;    // *를 붙임으로서 modifiable lvalue expression으로도 사용 가능

    const char* str = "Constant string";    // str : modifiable lvalue
    str = "Second string";    // Constant string은 단순히 값(constant)으로서 rvalue이지 lvalue로는 쓰일 수 없다.
    // str[0] = 'A';    // error
    puts(str);

    char str2[] = "String in an array"; // 배열로서 메모리 공간을 따로 할당을 받고 str2라는 identifier가 문자열이 저장되기에 충분한 메모리 공간에 대한 식별자 역할을 한다.
    str2[0] = 'A';   // 가능
    puts(str2);

    return 0;
}       