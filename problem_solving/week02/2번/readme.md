201927018 이정민


이 코드는 로마 숫자를 나타내는 문자열을 입력으로 받아 해당하는 정수 값을 반환하고, 입력된 로마 숫자가 유효한지 확인하는 기능을 가지고 있습니다.

코드는 먼저 "roman"이라는 이름의 순서 없는 맵을 정의하여 각 로마 숫자 문자를 해당하는 정수 값으로 매핑합니다. 그리고 이전 문자, 현재 문자, 문자가 연속해서 반복되는 횟수를 추적하는 변수들을 초기화합니다.

그 다음 코드는 입력된 문자열을 반복하면서 현재 문자와 이전 문자 변수를 업데이트합니다. 코드는 로마 숫자의 특정 규칙(문자가 반복될 수 있는 횟수, 문자가 나타나는 순서 등)을 확인하고, 입력이 이러한 규칙을 위반한다면 0을 반환합니다.

입력이 유효하다면, 코드는 현재 문자의 해당하는 정수 값을 누적 합계에 더하고, 다음 반복에서 사용하기 위해 현재 문자를 이전 문자로 설정합니다. 마지막으로, 코드는 입력된 문자열의 총 값을 반환합니다.

main 함수는 사용자가 "esc" 키를 누를 때까지 반복해서 사용자 입력을 받습니다. 사용자 입력이 유효한 로마 숫자인지 "isRomanNumeral" 함수를 사용하여 확인하고, 유효하다면 "romanToInt" 함수를 사용하여 해당 정수 값을 변환하고 결과를 출력합니다. 입력이 유효하지 않은 경우 오류 메시지를 출력합니다. 
