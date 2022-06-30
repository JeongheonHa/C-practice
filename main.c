// 변수, printf, 주석

#include <stdio.h> // standardinputouput을 담당하는 기능이 stdio라이브러리 어딘가에 있으니 내 프로그램에 포함시켜라

int main()
{   
    int x; // 변수 선언, int : 정수 자료형 , int X 와는 다른 변수, 숫자가 먼저올수 없다, 빈칸이 있으면 안된다, 언더바가 앞에오는거 가능
           // int x, y, z; 로 선언 가능 
    int y;
    int z;

    x = 1; // 할당
    y = 2;
    z = x + y;

    printf("The truth is \nI am ironman\n"); // \n (escape sequence) : 줄 바꿈, \" : "를 출력 
    printf("the answer is %i." , z); // printf (print formatted)
    printf("%i + %i = %i", x, y, z); // i에 x, y, z 순서대로 출력
    printf("\a"); // 경고음 출력

    /* 주석 */
    
    // Keywords : c언어에서 사용하는 단어들 (https://en.cppreference.com/w/c/keyword)
    // 예약어 : (since c ~ ) 
    // keywords와 예약어는 변수명이나 함수명으로 사용 X

    return 0;
}

