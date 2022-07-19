/* 메모리 누수와 free()의 중요성 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Dummy Output\n");

    {
        int n = 100000000;
        int* ptr = (int*)malloc(n * sizeof(int));

        if (!ptr)   // if(ptr == NULL)
        {
            printf("Malloc() failed\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < n; ++i)
            ptr[i] = i + 1;
    }
}