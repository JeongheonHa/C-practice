/* 배열을 입력받는 방법들 */

#include <stdio.h>
#define STRLEN 81


int main()
{
    /* creating space */

    // // char* name = ""; // runtime error, 입력받을 메모리 공간을 확보하지 않았다.
    // char name[128]; // 배열의 메모리 공간을 미리 확보
    // int result = scanf("%s", name);

    /* scanf() vs gets() */
    // // scanf() : 빈칸이 있을 경우 한 단어밖에 읽을 수 없다.
    // // gets() : 한 줄을 모두 읽을 수 있다. (엔터를 입력하는 순간 버퍼에 있는 내용을 gets가 읽어드리며 마지막의 줄바꿈(\n)을 제거하고 \0(null character)을 추가한다.)
    
    // char words[STRLEN] = "";
    // gets(words);    // gets는 포인터를 받은 상황, gets함수 입장에서는 배열의 첫번째 주소를 받기때문에 메모리 공간이 어디서 시작하는지는 알지만 어디서 끝나는지는 모른다.
    // // gets_s(words, sizeof(words));   //sizeof(words) -> STRLEN 가능, c99만 지원하는 컴파일러에서는 사용 x, c11을 지원하는 컴파일러는 가능
    // printf("START\n");
    // printf("%s", words);
    // puts(words);
    // puts("END.");

    /* fgets() vs fputs() */
    // // gets함수를 이용할 경우 배열의 길이를 넘어가는 문자열을 입력할 경우 runtime error가 발생하지만
    // // fgets함수를 이용하면 배열의 길이를 넘어가는 문자열을 입력해도 error가 발생하지않는다.
    // // fgets함수는 file을 입력받을때 사용하는 것이지만 stdin을 넣어주면 콘솔입력을 받을 때도 사용 가능.
    // // fgets함수는 문자열이 언제 끝날지 모른다는 것을 인지하고 함수를 실행한다.

    // char words [STRLEN] = "";
    // fgets(words, STRLEN, stdin);    // stdin : standard input, 원래는 stdin자리에 file에 대한 포인터를 넣어줄 수 있다.
    //                                 // 메모리 공간에서 사용자가 입력한 줄바꿈(\n)을 제거해주지 않는다. 있는 그대로 file로부터 읽어온다.

    // /* '\n'을 '\0'로 바꾸는 방법 */
    // int i = 0;
    // while (words[i] != '\n' && words[i] != '\0')
    //     i++;
    // if (words[i] == '\n')
    //     words[i] = '\0';

    // fputs(words, stdout);   // stdout : 콘솔 창으로 출력하게 해준다. file을 출력할때는 정확히 필요한 데이터만 파일에 저장해야하기 때문에 맨 뒤에 '\n'을 추가하지 않는다.
    // fputs("END", stdout);

    /* small array */
    
    // char small_array[5];
    // puts("Enter long strings:");

    // <1>
    // fgets(small_array, 5, stdin);   // 123456789 입력
    // fputs(small_array, stdout);  // 1234 출력 (\n포함 5개)

    // <2>
    // // fgets함수를 사용할 경우 반환 값이 존재한다. 정상적으로 입력을 받을 경우 입력받은 포인터를 반환
    // // 문제가 있거나 End Of File (EOF)를 만날 경우 '\0'(null character)를 반환
    // printf("%p\n", small_array);    // 0x16b83b44b, small_array의 주소
    // printf("%p\n", fgets(small_array, 5, stdin));   // sdfsdfsdf 입력, 반환 값 0x16b83b44b 출력 / ^Z 입력시 00000000 반환 
    // fputs(small_array,stdout);  // sdfs 4글자만 입력을 받았기 때문에 sdfs 출력 ('\n' 포함 5글자)

    /* repeating short reading */
    // // 긴 문자를 한번에 입력받아서 한번에 출력 (내부적으로 버퍼를 사용하기 때문에)
    // char small_array[5];
    // puts("Enter long strings:");
    // while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
    //     fputs(small_array, stdout);

    /* scanf() */
    
    char str1[6], str2[6];
     int count = scanf("%5s %5s", str1, str2);   // scanf로 입력을 받을 때 글자 수 제한 가능, null을 고려해 5개로 제한
    // int count = scanf("%6s %6s", str1, str2);   // runtime error 발생
    // int count = scanf_s("%5s %5s", str1, 6, str2, 6);
    printf("%s|%s \n", str1, str2); // 12345|67891 


    /* 문자열 입력 함수를 만들어서 사용한 예 */ // 다른 언어를 사용할 경우 기본 라이브러리에서 제공해준다.
    // char word[11];
    // puts(custom_string_input(word, 11));

    return 0;
}   

char* custom_string_input(char* st, int n)
{
    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);
    if (ret_ptr)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_ptr;
}

