/* 열거형 */

#include <stdio.h>

/* 
    // <motivation> 
    int c = 0;  // red : 0, orange : 1, yellow : 2, green : 3 ....
    if (c == 0)
        printf("red");
    else if (c == 1)
        printf("orange");
    else if (c == 2)
        printf("yellow");
    ... ...
    // 숫자에 대응하는 색을 정의 한다고 할때 값이 많을 경우 모두 다 사용자가 기억하면서 코딩을 해야한다.
*/

/*
    #define RED    1
    #define ORANGE 2
    #define YELLOW 3

    int c = YELLOW;
    if (c == YELLOW)
    if (c == YELLOW)
        printf("yellow");
    // compile 하기 전에 기계적으로 YELLOW에 3을 복사 붙여넣기를 하는 것 뿐이기 때문에 compiler가 오류가 있는 것을 잡아주지 못한다.
*/

int main()
{
    /*
        Enumerated type
        - Symbolic names to represent integer constants
        - Improve readability and make it easy to maintain
        - enum-specifier (struct-specifier, union-specifier) (지정자)

        Enumerators (red, orange ...)
        - The symbolic constants
    */

    enum spectrum { red, orange, yellow, green, blue, violet };
    //               0     1        2      3     4      5   

    enum spectrum color;
    color = blue;
    if (color == yellow)    // yellow는 문자열이 아닌 정수일 뿐이다. (2라는 정수에게 yellow라는 이름을 붙여줘서 이름을 이용해 숫자를 사용하게 해줄 뿐)
        printf("yellow");

    for (color = red; color <= violet; color++) // NOTE : ++ operator doesn't allowed in C++ (use int type)
        printf("%d\n", color);

    printf("red = %d, orange = %d\n", red, orange);

    // <ex>

    enum kids { jackjack, dash, snoopy, nano, pitz };
    enum kids my_kid = nano;
    printf("nano %d %d\n", my_kid, nano);

    enum levels { low = 100, medium = 500, high = 2000 };

    int score = 800;
    if (score > high)
        printf("High score!\n");
    else if (score > medium)
        printf("Good job\n");
    else if (score > low)
        printf("Not bad\n");
    else 
        printf("Do your best\n");

    enum pet { cat, dog = 10, lion, tiger };    // 중간에 값을 배정할 수 있다. (cat = 0, dog = 10, lion = 11, tiger = 12)

    printf("cat %d\n", cat);
    printf("lion %d\n", lion);

    return 0;
    
}
