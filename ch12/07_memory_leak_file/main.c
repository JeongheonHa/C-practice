/* 메모리 누수와 free()의 중요성 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Dummy Output\n");
    int* ptr_backup = NULL;
    // for(int k = 0; k < 1000000; ++k) // 메모리 할당을 free없이 계속 줄 경우 (메모리 누수, 절대 발생해서는 안된다.)
    {
        int n = 100000000;
        int* ptr = (int*)malloc(n * sizeof(int));   // ptr 변수는 block을 나가면 stack에서 사라진다.

        if (!ptr)   // if(ptr == NULL)
        {
            printf("Malloc() failed\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < n; ++i)
            ptr[i] = i + 1;

        printf("%d %d\n", ptr[0], ptr[1]);

        ptr_backup = ptr;   // 주소를 옮겨적어 놓았다면 ptr변수가 block을 나가 사라져도 ptr_backup 변수로 다시 사용할 수 있다.

        // free(ptr);
        // ptr = NULL;
    }

    printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
    printf("Dummy Output\n");

    return 0;
}