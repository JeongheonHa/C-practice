/* 레지스터 변수 */
/*
    cpu가 갖고있는 임시 작업 공간
    메모리는 물리적으로 cpu와 분리되어 있고 매인보드에 있는 bus를 통해 데이터를 주고 받기 때문에 시간이 걸린다.
    register는 메모리 처럼 데이터를 가지고 있을 수 있으며 cpu의 일부이기 때문에 빠르게 작동한다.
    사용자는 register라는 키워드를 이용해 register 공간에 데이터를 저장해달라고 요청은 할 수 있지만 compiler가 받아들이지 않을 수 있고
    stack에 저장하여 자동 변수처럼 사용할 수 있다.
    gpu, 병렬 처리, 분산 처리, simg 최후의 수단으로는 inline으로 assembly를 사용하지 rigister는 잘 사용하지 않는다.
*/

#include <stdio.h>

void temp(register int r)
{

}

int main()
{
    register int r;
    r = 123;

    // printf("%p\n", &r);
    // int* ptr = &r;  // register에 저장된 변수는 주소를 가져올 수 없다. 따라서, &(address of operator)를 사용할 수 없다.

    return 0;
}