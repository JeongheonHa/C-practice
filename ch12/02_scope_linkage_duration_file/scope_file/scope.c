/* 변수의 영역과 연결 상태, 객체의 지속 기간 */

#include <stdio.h>

/* 
    variable scopes (visibility (가시성))
    - 4가지 : block, function, function prototype, file.
*/

/* file scope */

// int g_i = 123;  // golbal variable (전역 변수), scope_linkage_duration.c 파일의 file scope에 선언한 것
// int g_j;    // global variable,

// void func1()
// {
//     g_i++;
// }

// void func2()
// {
//     g_i += 2;
// }

// int main()
// {
//     int local = 1234;

//     func1();
//     func2();

//     printf("%d\n", g_i);
//     printf("%d\n", g_j);    
//     // 초기화 되지 않은 전역, 정적변수의 경우 BSS라는 메모리 공간에 저장이 되며 프로그램이 처음 시작될 때 모두 한번에 0으로 초기화(효율적으로 하기위해)
//     printf("%d\n", local);

//     return 0;
// }

/* function prototype scope */

void f1(int hello, double world);   // prototype 선언이 끝날때 까지 존재
// VLA는 길이를 지정해줘야 하기 때문에 프로토타입에서 식별자를 생략할 수 없습니다.
// void vla_param(int n, int m, double ar[n][m])

/* block, function scope */
// double func_block(double d)
// {
//     double p = 0.0;

//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         double q = d* i;
//         p *= q;

//         if (i == 5)
//             goto hello;
//     }

// hello :
//     printf("Hello, World");

//     return p;
// }

// int main()
// {
//     func_block(1.0);
// }

// void f1(int hello, double world)
// {

// }

// void vla_param(int n, int m, double ar[n][m])
// {

// }