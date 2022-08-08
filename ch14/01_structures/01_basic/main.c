/* 구조체가 필요한 이유 */

/*
    배열은 자료형이 같은 데이터 오브젝트들이 나열된 형태

    // <structures>
    - 구조체는 서로 다른 자료형의 데이터들을 하나로 묶어 사용자가 직접 만든 자료형인 것 처럼 사용하는 형태

    #define MAX_NAME 20

    struct Patient
    {
        char name[MAX_NAME];    // 구조체 안에 있는 자료형들을 member라고 부른다.
        float height;
        float weight;
        int age;
    };

    struct Patient p1, p2, p3;  // structure variables, (하나의 자료형처럼 사용), Patient를 tag라고 부른다.

    ------------------------------------------------------------------------------------------------
    |                  p1.name                 |     p1.height     |     p1.weight     |   p1.age  |
    ------------------------------------------------------------------------------------------------
    |                  p2.name                 |     p2.height     |     p2.weight     |   p2.age  |
    ------------------------------------------------------------------------------------------------
    |                  p3.name                 |     p3.height     |     p3.weight     |   p3.age  |
    ------------------------------------------------------------------------------------------------

    Dot(.) : structure membership operator (member access operator, member operator) (각각의 member들에게 접근하고 싶을 때 사용)
    메모리 패딩 (padding) : 각 멤버들 사이의 빈 공간의 컴파일러가 최적화해주는 것
*/

/* 구조체의 기본적인 사용법 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person   // person is a tag of structure (변수명 짓는 규칙과 동일)
{
    char name[MAX]; // member
    int age;        // member
    float height;   // member
};
// 구조체를 선언하는 단계에서는 메모리를 갖지 않고 변수를 선언할 때 메모리를 갖는다. (틀 만 잡아놓는 단계)

int main()
{
    int flag;   // scanf의 반환 값을 받기위해 선언한 변수

    /* structure variable */
     
    struct person genie;    // 멤버들의 메모리 할당

    strcpy(genie.name, "Will smith");

    genie.age = 1000;   // dot(.)을 통해 접근하여 일반적인 변수처럼 사용 (단지 dot을 이용하여 구조체에서 변수를 접근하는 것 뿐)

    flag = scanf("%f", &genie.height);  // dot(.) has higher precedence than &
    printf("%f\n", genie.height);

    /* initialization */
    // 배열을 초기화 해줄 때와 비슷하지만 형태가 다른 값들도 한번에 초기화 가능

    // <1>
    struct person princess = { "Naomi Scott", 18, 160.0f }; // 멤버들을 선언해주는 순서와 초기화하는 순서가 동일해야한다.

    /* (다른 표현)
        struct person princess2 =  
        {
            "Naomi Scott",
            18,
            160.0f
        };
    */

    // <2> 변수를 하나하나 선언해주는 방법
    strcpy(princess.name, "Naomi Scott");
    princess.age = 18;
    princess.height = 160.0f;

    /* Designated initializers */
    // 변수를 지정해서 값을 초기화하는 것이기 때문에 순서가 바뀌어도 상관 없다는 장점이있다.
    struct person beauty =
    {
        .age = 19,
        .name = "Bell",
        .height = 150.0f
    };

    // struct person beauty = {.age = 19, .name = "Bell", .height = 150.0f} (다른 표현)

    /* Pointer to a structure variable */

    struct person* someone; // person이라는 tag를 갖는 구조체 변수의 포인터
    
    someone = &genie;
    // someone = (struct Person*)malloc(sizeof(struct Person)); (동적 할당 가능)

    /* Indirect member(ship) operator (or structure pointer operator) */
    // 구조체 내의 member를 접근할때는 dot(.)을 사용하였지만 포인터를 이용하여 구조체 내의 member에 접근할 때는 ->를 사용한다.

    someone->age = 1001; // -> : arrow operator
    printf("%s %d\n", someone->name, (*someone).age);

    /* Structure declarations in a function */
    // 함수내에서 구조체 생성 가능 (해당 함수 내에서만 사용 가능)
    struct book
    {
        char title[MAX];
        float price;
    };

    /* No tag */

    struct {
        char farm[MAX];
        float price;
    } apple, apple2;    // structure variable을 직접 선언할 수 있다.

    strcpy(apple.farm, "Trade Joe");
    apple.price = 1.2f;

    strcpy(apple.farm, "Safeway");
    apple2.price = 5.6f;

    /* typedef and structure */

    typedef struct person my_person;    // struct person이라는 타입을 my_person으로 선언을 해준다.
                                        // my_person은 내부적으로는 struct person이라는 자료형의 변수이다.
    my_person p3;   // my_person이라는 자료형이 있는 것 처럼 사용 가능

    typedef struct person person;       // 같은 이름으로 선언할 수 있다. (일반적으로 많이 사용)

    person p4;

    typedef struct {                    // 구조체를 선언과 동시에 typedef를 선언할 수 있다.
        char name[MAX];
        char hobby[MAX];
    } friend;                           

    friend f4;                          // friend라는 자료형이 있는 것 처럼 사용 가능

    return 0;
}