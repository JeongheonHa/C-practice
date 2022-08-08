/* 구조체의 배열을 사용하는 함수 */

#include <stdio.h>
#include <stdlib.h>
#define SLEN 101

struct book
{
    char name[SLEN];
    char author[SLEN];
};
// <1>
// void print_books(const struct book books[], int n);

// <2>
void print_books(const struct book* books, int n);

int main()
{
    // <1>
    // struct book my_books[3]; // { {"The Great Gatsby", "F.scott Fitzgerald"}, ...}; 도 가능
    
    // <2>
    // 동적 할당을 사용한 경우
    struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);

    if (!my_books) //malloc이 실패해서 my_books가 NULL 포인터인 경우
    {
        printf("malloc failed");
        exit(1);
    }

    my_books[0] = (struct book){"The Great Gatsby", "F.scott Fitzgerald"};
    my_books[1] = (struct book){"Hamlet", "William Shakespeare"};
    my_books[2] = (struct book){"the Odyssey", "Homer"};

    print_books(my_books, 3);

    return 0;
}
// <1>
// void print_books(const struct book books[], int n)
// {
//     for (int i = 0; i < n; ++i)
//         printf("Book %d : \"%s\" written by \"%s\"\n",
//             i + 1, books[i].name, books[i].author);
// }

// <2>
void print_books(const struct book* books, int n)
{
    for (int i = 0; i < n; ++i)
        printf("Book %d : \"%s\" written by \"%s\"\n",
            i + 1, books[i].name, books[i].author);
}