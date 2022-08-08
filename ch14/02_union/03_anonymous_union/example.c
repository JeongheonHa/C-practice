#include <stdio.h>

int main()
{
    struct Vector2D {
        union {
            struct { double x, y; };
            struct { double i, j; };
            struct { double arr[2]; };
        };
    };

    typedef struct Vector2D vec2;

    vec2 v = { 3.14, 2.99 };
    printf("%.2f %.2f\n", v.x, v.y);            // 3.14 2.99
    printf("%.2f %.2f\n", v.x, v.y);            // 3.14 2.99
    printf("%.2f %.2f\n", v.arr[0], v.arr[1]);  // 3.14 2.99

    return 0;
}