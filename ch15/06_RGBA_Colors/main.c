/* RGBA 색상 비트 마스크 */

#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{
    unsigned int rgba_color = 0x66CDAAFF;
    //  4 bytes, mediun aqua marine (102, 205, 170, 255)
    //                                R    G    B    A
    unsigned char red, green, blue, alpha;

    //Use right shift >> operator
    alpha   = rgba_color & BYTE_MASK;    // 투명도
    blue    = (rgba_color >> 8 & BYTE_MASK);
    green   = (rgba_color >> 16 & BYTE_MASK);
    red     = (rgba_color >> 24 & BYTE_MASK);

    printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
        red, green, blue, alpha);   // (R, G, B, A) = (102, 205, 170, 255)

    return 0;
}