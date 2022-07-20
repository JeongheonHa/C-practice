/* 파일 입출력의 작동 원리 */

/*
    <consol>
    c언어로 프로그램을 작성하고 실행을 할 경우 운영체제와의 관계에서 stdout, stderr, stdin stream이 열린다.
    stdout : printf와 같이 화면에 출력하는 함수들은 stdout stream을 사용한다.
    stdin : scanf와 같이 입력을 받는 함수들은 stdin stream을 사용한다.
    stderr : 정상적인 출력 stream이 아닌 긴급하게 출력을 해야하는 경우나 정상적인 출력과 구분이 되게 별도의 stream을 
             사용하여 저장이나 출력 등을 하고 싶을 때 stderr stream을 사용한다.
    redirection (방향 재지정) : 화면에 출력될 것을 파일에 출력하고 싶을 때 사용한다.

    <file>
    파일의 데이터를 저장하거나 파일의 데이터를 읽어오고 싶을 경우
    - ex) 백업, 복원, 게임의 save 기능 등등
    - 파일 입출력 기능을 파일 stream이라는 통로를 통해 사용한다.
    - 파일에 데이터를 저장하거나 파일의 데이터를 읽어올 때 2가지 mode 사용 가능 (Text files io stream, binary files io stream)

    <text files>
    - 보통 사람이 직접 읽기 위해서 사용 (문자로서 저장)
    - ex) fprintf(fp, "%d\n", i);
    - int i = 34567; , '3' '4' '5' '6' '7' 각각을 문자로 저장

    <binary files>
    - 순수하게 데이터만 저장 (이진수로 저장)
    - ex) fwrite(&i, sizeof(i, 1, fp);
    - int i = 34567; , 1000 0111 0000 0111 (2진수 그대로 저장)
*/ 