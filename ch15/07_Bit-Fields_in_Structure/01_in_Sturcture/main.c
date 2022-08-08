/* 구조체 안의 비트필드 */

#include <stdio.h>
#include <stdbool.h>

struct 
{
    bool has_sword    : 1;  // 1byte중 1bit만 차지
    bool has_shield   : 1; 
    bool has_potion   : 1;
    bool has_guntlet  : 1;
    bool has_hammer   : 1;
    bool has_key      : 1;
    bool has_ring     : 1;
    bool has_amulet   : 1;
} items_flag;   // items_flag가 차지하는 메모리 크기는 8비트 (1byte)

//  1 : 사용할 비트의 개수 (byte X), 꼭 1비트 만이 아니여도 된다.
// bool : 비트 필드의 값을 어떤 정수 자료형으로 해석하지 (주로 signed vs unsigned 차이)

int main()
{
    items_flag.has_sword = 1;   // flags = flags | MASK_SWORD;
    
    return 0;
}

