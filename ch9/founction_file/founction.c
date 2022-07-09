/* 함수의 필요성 */

// 일반화 (1억개라고 생각)
// 같은 기능이 여러번 나오면 안된다. (유지보수를 쉽게 하기위해)
// 정의 : body까지 모두 함수내에 있는 경우, 선언 : 이런 함수가 있다는 것을 알려주는 경우
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 20
#define NAME "Jeong-heon Ha"
#define ADDRESS "Jeonju, korea"

// 함수의 prototype, complie error 발생 X, linking X (body가 없을 때)
// complie할때는 프로토타입만을 가지고 compile하고 실행파일을 만드는 단계에서 linking을 통해 함수를 끼워 맞춘다. 단계 : compile + link -> build
// 함수를 선언하는 부분에서는 어떤 함수를 입출력할 것인가만 필요 (즉, ()안에 변수이름, 자료형이 없어도 된다. 단, (void) X)
void print_chars(char c, int n_stars, bool print_newline);  
void print_centerd_str(char str[]);

int main()
{
    print_chars('*', WIDTH, false); // 함수를 사용한다는 개념에서 볼때 ()안 : 인자 (arguement = 값)
    printf("\n");

    print_centerd_str(NAME);
    print_centerd_str(ADDRESS);

    print_chars('*',WIDTH, true);
    printf("\n");

    return 0;
}

void print_chars(char c, int n_stars, bool print_newline)    // void : 함수의 반환 자료형, 함수가 입력값을 받고 내놓는 반환값의 자료형의 자료형이 무엇인지
                                                             // 함수의 반환 자료형이 int인 경우 생략 가능
                                                             // () : 함수내에 입력받을 값이 있을 경우 입력받을 변수 지정
{
    for (int i = 0; i < n_stars; ++i)
        printf("%c", c);

    if (print_newline)
        printf("\n");
}

void print_centerd_str(char str[])  // 함수를 매개 변수화 했다. 함수를 정의한다는 개념에서 볼때 ()안의 변수 : 매개 변수 (parameter)
                                    // parameter에 arguement를 넣는다고 생각
{
    int n_blanks = 0;

    n_blanks = (WIDTH - strlen(str)) / 2;
    print_chars(' ', n_blanks, false);
    printf("%s\n", str);
}
