/* 저장 공간의 다섯가지 분류 */

/*
     저장 공간 분류         메모리에서의 위치        지속 기간         영역        연결 상태            선언 방법
    storage class       memory segment      duration        scope       linkage         how declared
    ----------------------------------------------------------------------------------------------------------------
    automatic               stack           자동으로 결정       블록 안        없음              블록 안
    ----------------------------------------------------------------------------------------------------------------
    register            레지스터 (or 스택)     자동으로 결정       블록 안        없음              register 키워드 사용
    ---------------------------------------------------------------------------------------------------------------- <-- 여길 기준으로 2가지로 나누기도함
    고정적, 내부 연결       데이터 or BSS           고정적         파일 안        번역 단위의         모든 함수들 밖에서
    (static with internal linkage)                                       내부에서만 사용      static 키워드 사용
    ----------------------------------------------------------------------------------------------------------------
    고정적, 외부 연결       데이터 or BSS           고정적         파일 안        번역 단위의         모든 함수들 밖
    (static with external linkage)                                       외부로도 연결 가능
    ----------------------------------------------------------------------------------------------------------------
    고정적, 연결 없음       데이터 or BSS           고정적         블록 안        없음              블록 안에서 static 키워드 사용
    (static with no linkage)
    ----------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------
    할당 메모리              힙(heap)         프로그래머가 결정      NA          NA               운영체제에게 요청
    (주의  : 식별자 없음, 운영체제는 주소만 던져준다.)
    ----------------------------------------------------------------------------------------------------------------
*/

/* 
    automatic : 지금까지 사용한 모든 지역 변수들은 자동 변수이다.
                프로그램에서 계속 사용해야하는 변수가 아니라면 메모리를 계속 유지시킬 필요가 없기때문에 사용하지 않을 때는 다른 변수가 사용할 수 있게 메모리 공간을 내어준다.
    register : cpu안에 register가 있기 때문에 빠르다.(메모리는 cpu밖에 분리)
*/





    