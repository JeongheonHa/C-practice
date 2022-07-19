/* 메모리 동적 할당 */
/*
    저장 공간 분류         메모리에서의 위치        지속 기간         영역        연결 상태          선언 방법
    storage class       memory segment      duration        scope       linkage         how declared
    ----------------------------------------------------------------------------------------------------------------
    할당 메모리              힙(heap)         프로그래머가 결정      NA          NA               운영체제에게 요청
    (주의  : 식별자 없음, 운영체제는 주소만 던져준다.)
    ----------------------------------------------------------------------------------------------------------------
*/

//  compile 타임에는 메모리의 크기를 알 수 없고 runtime이 되어서 결정이 되는 것들

#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int main()
{
    /* 스택에 저장되는 것들 */
    /*
        float x;
        char str[] = "Dancing with a Star";

        int arr[100];
    */

    /*
        malloc() returns a void type pointer.
        void* : generic pointer (일반적인 주소)

        free() deallocates the memory
    */
    // 동적 할당에 배정된 주소자체는 변수(ptr)이기 때문에 stack에 저장되어 scope밖을 벗어날 경우 없어질 수 있지만 heap에 저장된 메모리 공간은 사라지지 않는다.
    // 하지만, 포인터를 잃어비린 것이기 때문에 접근할 수 없고 메모리 공간을 사용할 수 도 없다.

    double* ptr = NULL; // ptr을 배열로서 사용 

    ptr = (double*)malloc(30 * sizeof(double)); // 파리미터에 멏 바이트의 메모리를 요청할지 size를 넣어준다.
                                                // void 타입의 주소만을 리턴해주기때문에 사용하는 쪽에서 casting을 통해 형변환을 한다.
    if (ptr == NULL)    // 더 이상 메모리 할당을 실행할 수 없는 경우 NULL 포인트를 반환
                        // 또는, 여러 프로그램을 많이 끼워놓아 운영체제가 연속된 공간을 할당할 수 없을 경우
    {
        puts("Memory allocation failed.");

        /* 
            exit(EXIT_FAILURE) is similar to return 1 IN main(). (main함수에서 1을 반환한다는 것은 문제가 있다는 것을 os에게 알리는 것, exit은 어떤 함수든 가능)
            exit(EXIT_SUCCESS) is similar to return 0 IN main().
        */

        exit(EXIT_FAILURE); // exit이라는 함수를 이용하여 강제로 종료하는 것이 일반적이다.
    }

    printf("Before free %p\n", ptr);    // Before free 0x151e06790

    free(ptr);  // 반드시 반납을 하여 해당 공간을 다른 용도로 사용할 수 있게 해야한다. (ptr에 NULL 포인터인 경우 free를 사용할 때 아무 일도 일어나지 않는다)

    printf("After free %p\n", ptr);     // After free 0x151e06790, free를 했음에도 주소값을 갖고있는 이유는 ptr은 별도의 변수이기 때문에 해당 메모리 공간의 쓰임이 
                                        // 바뀌었어도 해당 메모리의 주소를 갖고있다. (종이지에 주소만 적어놓는 것과 같다)

    ptr = NULL; // ptr 변수 또한 NULL 값으로 초기화 해준다.


    /* Dynamically Allocated Array */

    int n = 5;
    ptr = (double*)malloc(n * sizeof(double));  // expression을 통해 parameter를 지정할 수 있다.
                                                // sizeof는 compile하기전에 결정이 되고, n은 runtime에 결정이 되어도 상관없다.
                                                // 즉, 실행을 해봐야 n을 알 수 있는 경우에도 사용 가능
                                                // 또한 malloc함수를 이용해 메모리를 할당 받을 때는 0으로 초기화 해주지 않는다.
    if (ptr != NULL)
    {
        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");

        for (int i = 0; i < n; ++i)
            * (ptr + i) = (double)i;

        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");
    }

    free(ptr);
    ptr = NULL;

    /* Comparision to VLA */
    /*
        VLA 
        - not supported by VS compilers.
        - automatic duration, cannot be resized () (일반적인 변수처럼 stack에 올라간다, 한번 받아오면 길이가 고정)
        - limited by stack size (when compiler places VLA in stack segment (컴파일러마다 다름)) (stack size가 그렇게 크지 않기 때문에)

        동작 할당 
        - (다른 사이즈의 메모리를 다시 받아온다는 개념이 더 정확)
        - 내가 free를 요청할 때까지 heap 머문다.
        - heap의 size는 크지만 어디있는지 찾기가 힘들다.
    */

    return 0;

}

