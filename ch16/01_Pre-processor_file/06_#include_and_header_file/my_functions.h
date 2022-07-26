#pragma once    // header guard
// 헤더가드가 없는 경우 A.h를 B.h가 include하고 main.c에서 A.h와 B.h를 모두 include한다면 main.c에서는 A.h가 B.h를 통해서
// 한번 더 include되는 형태이다.

// #ifndef __MY_FUNCTIONS__    // 선언이 안되어 있다면 (옛날 방식, 지금은 #pragma once를 사용)
// #define __MY_FUNCTIONS__    // 선언

#include "my_functions.h"

extern int status;

static int si = 0;

extern int add(int a, int b);

static int multiply(int a, int b)
{
    return a * b;
}

inline int subtract(int a,int b)
{
    return a - b;
}

void print_status();
void print_address();

// #endif
