/* 비트 단위 논리 연산자 */

/*
    일반적인 논리 연산자 : &&, ||, !

    비트 단위 논리 연산자 :
    - Bitwise NOT           ~ (Tilde)
    - Bitwise AND           & (Ampersand)
    - Bitwise OR            | (Vertical bar)
    - Bitwise EXCLUSIVE OR  ^ (Caret)
*/

// 8 byte의 참 거짓만 을 확인하는 정의를 할때 1, 0 (1bit)만을 사용하지만 자료형의 최소 단위는 char이기 때문에 1byte당 나머지 7bit는 낭비가 될 수 있다.
// 이것을 8bit의 2진수 연산을 통해 해결할 수 있다. (비트 연산)

/*
    <Bitwise AND &>
                                    Decimal               Binary
    unsigned char a = 6;            6 = 2^2 + 2^1         00000110
    unsigned char b = 5;            5 = 2^2 + 2^0         00000101
    printf("%hhu", a & b);          4 = 2^2               00000100

    // 둘 다 1이면 1
    0 & 0 -> 0
    0 & 1 -> 0
    1 & 0 -> 0
    1 & 1 -> 1
*/

/*
    <Bitwise OR |>
                                    Decimal               Binary
    unsigned char a = 6;            6 = 2^2 + 2^1         00000110
    unsigned char b = 5;            5 = 2^2 + 2^0         00000101
    printf("%hhu", a | b);          7 = 2^2 + 2^1 + 2^0   00000111

    // 둘 중에 하나만 1이면 1
    0 | 0 -> 0
    0 | 1 -> 1
    1 | 0 -> 1
    1 | 1 -> 1
*/

/*
    <Bitwise Exclusive OR ^>
                                    Decimal               Binary
    unsigned char a = 6;            6 = 2^2 + 2^1         00000110
    unsigned char b = 5;            5 = 2^2 + 2^0         00000101
    printf("%hhu", a ^ b);          3 = 2^1 + 2^0         00000011

    // 둘다 1이면 0, 둘 중 하나 1이면 1
    0 ^ 0 -> 0
    0 ^ 1 -> 1
    1 ^ 0 -> 1
    1 ^ 1 -> 0
*/

/*
    <Bitwise Not ~>
                                    Decimal               Binary
    unsigned char a = 6;            6 = 2^2 + 2^1         00000110
    printf("hhu", ~a);              249                   11111001

    // 0이면 1, 1이면 0
*/