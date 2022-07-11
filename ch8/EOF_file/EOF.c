/* end of file */

#include <stdio.h>

int main()
{
    int c;

    while (( c = getchar()) != EOF) // getchar함수는 리턴값을 int value로 넘겨준다. EOF는 <stdio.h>에 -1로 define되어있다.
    {                                // getchar함수는 더 이상 입력받을 것이 없을 때 -1을 return하며 EOF와 같아지며 while문 탈출
                                    // ctrl + z를 누르면 -1을 buffer로 넘겨준다. 
        putchar(c);
    }
    
    return 0;
}