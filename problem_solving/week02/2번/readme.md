201927018 이정민


vector<pair<int, string>> romanumerals : 로마숫자와 아라비아숫자의 대응 관계를 저장한 벡터를 선언합니다.
get_number(string roman_numeral) 함수: 문자열 roman_numeral을 인자로 받고, 해당 로마숫자에 대응하는 아라비아숫자를 반환합니다.
result 변수를 선언하고 0으로 초기화합니다. 이 변수에 로마숫자를 아라비아숫자로 변환한 결과를 누적합니다.

for 반복문에서 romanumerals 벡터에 저장된 로마숫자와 아라비아숫자 쌍에 대해 반복합니다.
while 반복문에서 roman_numeral 문자열의 앞부분이 현재 로마숫자와 일치하는지 확인합니다. 일치한다면, result에 해당 아라비아숫자를 더하고, roman_numeral 문자열의 일치하는 부분을 없애고 이 과정을 반복하여 모든 로마숫자에 대해 아라비아숫자를 계산합니다.
만약 결과값 result가 3999를 초과하면 invalid_argument 예외를 발생시킵니다.

main() 함수:
사용자로부터 로마숫자를 입력받습니다.
try-catch 문을 사용하여 입력받은 로마숫자를 get_number() 함수를 이용하여 아라비아숫자로 변환합니다. 변환 도중에 예외가 발생하면, invalid_argument 예외가 발생했다는 메시지를 출력합니다.
변환된 아라비아숫자를 출력합니다.
사용자로부터 로마숫자를 새로 입력받기 위해 입력 대기 상태로 돌아갑니다.
프로그램을 종료하려면 ESC 키를 누르면 됩니다.
