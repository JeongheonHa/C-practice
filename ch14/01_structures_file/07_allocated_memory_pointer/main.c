/* 구조체와 할당 메모리 */

#include <stdio.h>
#include <string.h> // strlen, strcmp
#include <stdlib.h> // malloc, free
#define SLEN 81

struct namect {
    char* fname;
    char* lname;
    int letters;
};

void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);

int main()
{
    /*
        Dangerous usage
    */

    // struct namect p = { "Jeong-heon", "Ha" };    // 문자열은 Text Segment에 저장이되어 첫번째 문자의 주소를 변수에 저장해 놓는 것이기 때문에
                                                 // 포인터로서 사용이되고 포인터는 하나의 값을 공유하는 형태이기 때문에 text segment의 값 하나를 사용
    // printf("%s %s\n", p.fname, p.lname);

    // int f1 = scanf("%[^\n]%*c", p.lname);       // 값을 바꾸려고 시도하기 때문에 error 발생
    // printf("%s %s\n", p.fname, p.fname);

    /*
        Recommended usage
    */
    // struct namect p = { "Jeong-heon", "Ha" };

    // char buffer[SLEN] = { 0, };
    // int f2 = scanf("%s[^\n]%*c", buffer);
    // p.fname = (char*)malloc(strlen(buffer) + 1);
    // if (p.fname != NULL)
    //     strcpy(p.fname, buffer);
    // printf("%s %s\n", p.fname, p.lname);

    /*
        function
    */

    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}

void getinfo (struct namect* pst)
{
    int flag;
    char temp[SLEN] = { 0, };

    printf("Please enter your first name.\n");

    flag = scanf("%[^\n]%*c", temp);

    if (flag != 1)
        printf("Wrong input");
    else
    { 
        pst->fname = (char*)malloc(strlen(temp) + 1);   // +1 is for '\0'

        if (pst->fname != NULL) // // 동적 할당에 문제가 있을 경우 NULL 포인터를 갖는다.
            strcpy(pst->fname, temp);
        else
            printf("malloc() failed");
    }

    printf("Please enter your last name.\n");

    flag = scanf("%[^\n]%*c", temp);

    if (flag != 1)
        printf("Wrong input");
    else
    { 
        pst->lname = (char*)malloc(strlen(temp) + 1);   // +1 is for '\0'

        if (pst->lname != NULL) // 동적 할당에 문제가 있을 경우 NULL 포인터를 갖는다.
            strcpy(pst->lname, temp);
        else
            printf("malloc() failed");
    }
}

void cleanup(struct namect* pst)
{
    free(pst->fname);
    free(pst->lname);
}

void makeinfo(struct namect* pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect* pst)
{
    printf("%s %s, your name contains %d letters.\n",
        pst->fname, pst->lname, pst->letters);
}