/* calloc & realloc */


#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
        calloc : contiguous allocation
        - 0으로 초기화 해준다. (malloc은 안해준다, 경우에 따라 좋을수도 나쁠수도 있다)
    */

    int n = 10;

    int * ptr = NULL;

    // ptr = (int*)malloc(sizeof(int) * n); 둘다 같은 의미
    ptr = (int*)calloc(n, sizeof(int)); // int형 사이즈 몇개를 할당 받을 것인가

    if (!ptr)
        exit(1);

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr[i]);  // 0 0 0 0 0 0 0 0 0 0 
    printf("\n");

    /*
        realloc()
        - 다시 할당을 받고싶을 때 사용하는 함수
        - doesn't initialize the bytes added (기존의 할당된 메모리 보다 더 필요로 한경우 기존 데이터를 복사하고 새로 추가된 부분은 초기화 해주지 않는다)
        - return NULL if can't enlarge the memory block
        - if first argument is NULL, it behaves like malloc() (ptr이 없다면)
        - if second argument is 0, it frees the memory block (기존 메모리 free)
        - malloc 이나 calloc으로 받아도 realloc 가능
    */

    for (int i = 0; i < n; ++i)
        ptr[i] = i + 1;

    n = 20; // n이 20으로 늘었다.

    int* ptr2 = NULL;
    ptr2 = (int*)realloc(ptr, n * sizeof(int)); // 다른 포인터 변수 선언, realloc(기존 메모리의 포인터, 새로 할당 받고 싶은 메모리 사이즈)
    // ptr = (int*)realloc(ptr, n * sizeof(int));   // 기존의 포인터에 메모리만 증가한 형태 (이렇게 사용할 수 있다.)

    printf("%p %p\n", ptr, ptr2);   // 0x128f04080 0x128f04080 (원래는 다른다)

    printf("%d\n", ptr[0]); // 1

    if (!ptr2)
        exit(1);
    else    
        ptr = NULL;

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr2[i]); // 1 2 3 4 5 6 7 8 9 10 0 0 0 0 0 0 0 0 0 0 (원래는 0 대신 쓰레기 값이 나온다)
    printf("\n");

    free(ptr2);
}