/* 단어 세기 */
// 빈칸 빼기, . 압력시 종료, 음절, 단어, 문장 개수 출력

/* 내 풀이 */
/*
#include <stdio.h>

int main()
{
    char ch;
    int countc = 0;
    int countw = 0;
    int countl = 0;

    printf("Enter text : ");
    
    while (ch != '.')
    {
        if((ch = getchar()) != '.' && ch != ' ')
        ++countc;

        if(ch == ' ')
        ++countw;
    }
    ++countl;
    printf("Characters = %d. Word = %d. Lines = %d\n", countc, countw, countl);

    return 0;
}
*/

/* 다른 풀이 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '.'

int main()
{
    char c;
    int n_chars = 0;
    int n_lines = 0;
    int n_words = 0;
    bool word_flag = false; // flag : 껏다 켰다한다는 느낌
    bool line_flag = false;

    printf("Enter text : ");

    while ((c = getchar()) != STOP)
    {
        if (!isspace(c))    // !isspace(c) : c가 ' ', '\n'이 아니라면
            n_chars++;

        if(!isspace(c) && !line_flag)   // !line_flag : line_flag가 true가 아니라면
        {
            n_lines++;
            line_flag = true;
        }
        
        if (c == '\n')
            line_flag = false;

        if (!isspace(c) && !word_flag)
        {
            n_words++;
            word_flag = true;
        }

        if (isspace(c))
            word_flag = false;
    }

    printf("Characters = %d, Word = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;
}