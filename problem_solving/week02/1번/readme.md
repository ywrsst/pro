201927018이정민

이 코드는 사용자로부터 1부터 3999 사이의 정수를 입력받아 해당하는 로마 숫자를 출력하는 프로그램입니다. 
프로그램 실행 중에는 사용자가 키보드에서 입력한 값으로 프로그램이 제어됩니다.

C++ 표준 라이브러리의 필요한 헤더 파일을 포함시킵니다.

주어진 숫자를 로마숫자로 변환하는 함수인 romanumeral 함수를 정의합니다.

main 함수에서는 사용자로부터 숫자를 입력받는 무한 루프를 시작합니다.

루프 안에서, _kbhit() 함수를 사용하여 사용자가 키보드에서 입력한 값이 있는지 확인합니다. _kbhit() 함수는 키보드 버퍼에 문자가 있다면 즉시 반환하고, 그렇지 않으면 대기합니다.

사용자가 ESC 키를 누르면 무한 루프를 종료합니다.

사용자가 숫자를 입력하면 cin >> num을 사용하여 입력받습니다. 입력받은 숫자가 1부터 3999 사이의 숫자이면, romanumeral 함수를 사용하여 해당하는 로마 숫자를 계산하고 출력합니다. 입력한 숫자가 범위를 벗어나면 예외를 처리합니다.

사용자가 잘못된 값을 입력하면 에러 메시지를 출력합니다.

cin.clear() 함수와 cin.ignore() 함수를 사용하여, 입력 버퍼에 남아있는 값들을 지우고, 다음 입력을 받을 수 있도록 합니다.

프로그램은 루프를 반복하면서 사용자로부터 입력을 기다립니다.

루프를 종료하면 프로그램이 종료됩니다.
