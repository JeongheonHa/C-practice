/* 문자열의 배열 */

#include <stdio.h>

int main()
{
    const char* mythings[5] = { // text segment안에 저장되어있는 문자열을 포인터로 가리키는 형태 , (이중 배열의 형태)
        "Dancing in the rain",
        "Counting apples",
        "Watching movies with friends",
        "Writing sad letters",
        "Studying the C language",
    };

    char yourthings[5][40] = {  // stack에 배열로서 메모리를 갖고있다. (별도 메모리에 값들이 복사해서 들어있는 형태)
        "Studying the C++ language",
        "Eating",
        "Watching Netflix",
        "Walking around till dark",
        "Deleting spam emails"
    };

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %llu %llu\n", mythings[0], (unsigned long long)mythings[0], (unsigned long long)temp1);
    // Dancing in the rain 4372643416 4372643416
    printf("%s %llu %llu\n", yourthings[0], (unsigned long long)yourthings[0], (unsigned long long)temp2);  
    // Studying the C++ language 6094254952 4372643525
    printf("\n");

    printf("%-30s %-30s\n", "My things:", "Your Things:");
    for (int i = 0; i < 5; i++)
        printf("%-30s %-30s\n", mythings[i], yourthings[i]);

    printf("\nsizeof mythings: %zd, sizeof your yourthings: %zd\n",
        sizeof(mythings), sizeof(yourthings));  // 40 (포인터 배열 5개의 주소) 200(행 5 * 열 40)

    for (int i = 0; i < 100; i++)
        printf("%c", mythings[0][i]);
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; i++)
        printf("%d", (int)yourthings[0][i]);
    printf("\n");

    for (int i = 0; i < 200; i++)
        printf("%c", yourthings[0][i]); // 글자수 보다 많은 index를 넣어주기 때문에 좋은 코드는 아니다.
    printf("\n");
    printf("\n");

    return 0;

}