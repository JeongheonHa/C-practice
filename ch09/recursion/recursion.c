/* 재귀 호출 */
// 무한 루프로써 재귀 호출 사용 X
// 효율적으로 사용하기위해서는 stop condition을 사용
// 각각의 n은 변수명만 같지 다른 메모리를 차지하는 다른 오브젝트
/*
# include <stdio.h>

void my_func(int);

int main()
{
    my_func(1);

    return 0;
}

void my_func(int n) // 함수도 스택이 쌓인다. (때문에 n의 주소의 데어터를 출력할 때 4byte보다 더 차이가 난다)
{
    printf("Level %d, address of variable n = %p\n", n, &n);    // 주소는 모두 다르다. 1234 출력 후 
    
    if(n < 4)
        my_func(n + 1); // 같은 함수로 다시 들어간다.
    
    printf("Level %d, address of variable n = %p\n", n, &n);    // 4321로 다시 돌아온다는 것을 보여주기 위해 printf해봄. (인셉션)
}
*/

/* 재귀 호출을 이용한 팩토리얼 */
/*
#include <stdio.h>

long loop_factorial(int n);
long recursive_factorial (int n);

int main()
{
    int num = 5;

    printf("%ld\n", loop_factorial(num));
    printf("%ld\n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n)
{
    long count;

    for (count = 1; n > 1; --n)
        count *= n; 

    return count;
}

long recursive_factorial (int n)
{
    if (n > 0)
    {
        return n * recursive_factorial(n - 1);  // tail recursion : return 앞에 재귀 호출을 구현하는 방법
    }
    else    
        return 1;
}
*/

/* 2진수 변환 */
/*
#include <stdio.h>

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
    unsigned long num = 10;

    print_binary(num);  // 1010
    printf("\n");
    print_binary_loop(num); // 0101
    printf("\n");

    return 0;
}

void print_binary_loop(unsigned long n)
{
    while(1)
    {
        int quotient = n / 2;
        int remainder = n % 2;

        printf("%d", remainder);

        n = quotient;

        if (n == 0)
            break;
    }
}

void print_binary(unsigned long n)
{
    int remainder = n % 2;

    if (n >= 2)
        print_binary(n / 2);
    printf("%d", remainder);
    
    return;
}
*/

/* 피보나치 수열 */

#include <stdio.h>

int fibonacci(int number);

int main()
{
    for (int count = 1; count < 13; ++count)
        printf("%d", fibonacci(count));

    return 0;
}

int fibonacci(int number)
{
    if (number > 2)
    {
        return fibonacci(number - 1) + fibonacci(number -2);
    }
    else    
        return 1;
}

/* 재귀 호출의 장단점 */
// 장점 : 수학적으로 정의가 되어있는 경우에 식이 간결해진다.
// 단점 : 메모리를 많이 사용한다, 계산에 중복이 생긴다.