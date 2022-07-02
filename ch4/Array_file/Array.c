/* 문자 배열 */
// 배열 : 같은 데이터 타입의 저장 공간을 여러개 확보하는 것

#include <stdio.h>

int main()
{
    // char fruit_name;    // 오직 1개의 문자만을 저장
    char fruit_name[40];    // char 타입 40개의 메모리 공간의 대표 주소 1개만 알려준다.
    // char 타입 40개가 나란히 배열되어있는 메모리 공간을 대표하는 주소가 fruit_name
    
    printf("What is your favorite fruit?\n");

    scanf("%s", fruit_name);   // 형식 지정자 %s (string)을 사용 
    // &은 주소를 불러오기위해 사용하지만 fruit_name자체가 대표 주소이기 때문에 &을 안붙인다.

    printf("You like %s\n", fruit_name);

    return 0;
}