/* 복합 리터럴 */

#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    // char* title;     // not recommended
    // char* author;    // not recommended
    float price;
};

struct rectangle
{
    double width;
    double height;
};

double rect_area(struct rectangle r)    // 값으로 받아오냐 차이
{
    return r.width * r.height;
}

double rect_area_ptr(struct rectangle * r)  // 포인터로 받아오냐 차이
{
    return r->width * r->height;
}

int main()
{
    struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };
    // 초기화를 할 때는 문법적으로 대입이 아니다.
    /*
        Compound literals
        - Temporary structure values
    */
    // book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f };    // 한번 초기화가 끝난 후에는 대입이 안된다.

    // <1>
    // member들에 각각 대입해주는 방법
    strcpy(book_to_read.title, "Alice in Wonderland");
    strcpy(book_to_read.author, "Lewis Carroll");
    book_to_read.price = 20.3f;

    // <2>
    // 다른 변수를 하나 만들어 바꾸고 싶은 값으로 초기화를 한 후 변수를 복사하는 방법
    // 값을 넣기위해 변수를 선언하는 것은 복사하는 것이기 때문에 데이터를 더 많이 차지하고 번거롭다.
    struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
    book_to_read = book2;

    // <3>
    // 복합 리터럴 *선호*     
    //             |-------------------------- Lvalue --------------------------|      
    book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f }; 

    printf("%s %s\n", book_to_read.title, book_to_read.author);

    // <4> 
    // 복합 리터럴의 특징 (Lvalue)

    // <4-1>
    // double area = rect_area((struct rectangle){ 1.0, 2.0 });   // Lvalue이기때문에 가능

    // <4-2>
    double area = rect_area_ptr(&(struct rectangle){ .height = 3.0, .width = 2.0 });   // designed initializers를 이용해 값을 결정할 수 있다.
    // 복합리터럴의 주소를 가져와서 rect_area_ptr()함수에 전달해줄 수 있다.
    // 복합리터럴에 메모리에 공간을 차지하고 있는 존재이기 때문에 주소를 가져올 수 있다.
    printf("%f\n", area);

    return 0;
}