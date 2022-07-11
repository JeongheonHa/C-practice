/* 배열 */

#include <stdio.h>

#define MONTHS 12

int main()
{
    /* 기본 사용 예 */
    /*
    int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

    for (int i = 0; i < MONTHS; ++i)    // index는 0부터 시작하기 때문에 12개를 비교한다면 11에서 끝나야한다.
        printf("%d", high[i]);
    printf("\n");

    float avg = 0.0;
    for (int i = 0; i < MONTHS; ++i)
        avg += high[i];
    printf("Average = %f\n", avg / (float)MONTHS);

    high[0] = 1;    // high[]를 변수로서 사용 가능
    high[1] = 2;
    */

    /* Address */
    /*
    printf("%p %p\n", high, &high[0]);
    for (int i = 0; i < MONTHS; ++i)
        printf("%lld\n", (long long)&high[i]);
    printf("\n");
    */
   
    /* error */
    // high[12] = 4;    // compile 단계에서는 error발생 X, runtime error 발생
    // high[-1] = 123;  //  index숫자가 유효한지 컴파일단계에서 확인 X, 실행되고나서 12번째 값이 없어 error 발생
    
    /* const & array */
    // int const low[6] = { -3, -5, 7, 8, 9, 11 };
    
    /* array 초기화를 안했을 때 */
    /*
    static int not_init[4]; // static을 붙일 경우 0 0 0 0으로 초기화
    for (int i = 0; i < 4; ++i)
        printf("%d\n", not_init[i]);    // 이상한 값 출력
    */

    /* index보다 적은 배열의 경우 */
    /*
    int init[4] = { 2, 4 };
    for (int i = 0; i < 4; ++i)
        printf("%d\n", init[i]);  // 2 4 0 0, 뒷 부분 0으로 알아서 초기화
    */

    /* index를 초과한 배열의 경우 */
    // int over[2] = {2, 4, 8, 16}; error 발생

    /* size 생략 */
    /*
    // size를 생략하는 경우 compile할때 컴퓨터가 자동으로 부여
    // 사용자는 index에 어떤 숫자가 들어갈지 모르기 때문에 for문을 만들 수 없다.
    int const power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64};
    printf("%d\n", sizeof(power_of_twos));  // 전체 배열의 크기를 측정
    printf("%d\n", sizeof(int));    // 각각의 자료가 담기는 칸의 size
    printf("%d\n", sizeof(power_of_twos[0]));   // 첫번째 데이터의 사이즈

    // 전체 배열의 size에서 첫번째 데이터 공간의 size를 나누면 1칸의 size를 알 수 있다. (단, 동적할당에서는 안된다.)
    for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)
        printf("%d ", power_of_twos[i]);
    */

    /* 초기화 지정 */
    /*
    int days[MONTHS] = {1, 2, [4] = 3 ,4, 5, [1] = 6};
    for (int i = 0; i < MONTHS; ++i)
        printf("%d ", days[i]); // 1 6 0 0 3 4 5 0 0 0 0, 1번째 자리에 6덮어쓰기
                                // 4번째에 3 지정하고 이 지점에서 순차적으로 배열
    */

    /* specifying array sizes */
    int arr1[MONTHS];   // 양의 정수만 가능
    double arr2[123];
    float arr3[3*2 + 2];    // 컴파일 단계에서 미리 계산할 수 있기 때문에 가능
    float arr4[sizeof(int) + 1];    // 컴파일 단계에서 int의 사이즈를 미리 계산할 수 있기 때문에 가능
    // float arr5[-1];  // X
    // float arr6[0];   // X
    // float arr7[1.5]; // X
    float arr8[(int)1.5];   // 가능
    return 0;
}