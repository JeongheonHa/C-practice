/* 함수 포인터의 사용 방법 */

#include <stdio.h>
#include <ctype.h>  // toupper(), tolower()

void ToUpper (char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

// <1> 두 함수를 합치는 법
// 함수를 파라미터로 받아옴으로서 두개의 함수를 합친다.
void UpdateString(char* str, int(*pf)(int))
{
    while (*str)
    {
        *str = (*pf)(*str);
        str++;
    }
}

int main()
{
    char str[] = "Hello, World!";

    void (*pf)(char*);
    
    pf = ToUpper;

    printf("String literal %lld\n", (long long)("Hello, World!"));  // String literal 4339990372 (text segment)
    printf("Function pointer %lld\n", (long long)ToUpper);          // Function pointer 4339989908 (text segment)
    printf("Variable %lld\n", (long long)str);                      // Variable 6126908552 (stack)

    (*pf)(str); // ToUpper(str); 과 같은 효과
    // pf(str); 같은 의미

    printf("ToUpper %s\n", str);     // ToUpper HELLO, WORLD!

    pf = ToLower;

    pf(str);

    printf("ToLower %s\n", str);    // ToLower hello, world!

    // <1>

    UpdateString(str, toupper); // 함수를 인자로 넣는다.

    printf("ToUpper %s\n", str);

    UpdateString(str, tolower);

    printf("ToLower %s\n", str);

    // Note : _cdecl is function calling convention (함수 호출 규약)
    // int (_cdecl *pf)(int))
    return 0;
}
