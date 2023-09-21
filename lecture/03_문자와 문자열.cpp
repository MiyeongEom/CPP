#include <iostream>
using namespace std;

// 문자와 문자열
// 사실 char도 마찬가지로 그냥 정수지만, '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자
// wchar_t : 유니코드 문자

char ch = 97; // a

// 아스키코드(ASCII)
char ch2 = 'a'; 
char ch3 = '1';  // 49
char ch4 = 'a' + 1; // b

// 국제화 시대에는 영어만으로 서비스 할 수 없음
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드(unicode)
// 참고) 가장 많은 번호를 차지하는게 한국어/중국어

// 유니코드는 표기 방식이 여러가지 있는데 대표적 UTF8 UTF16
// UTF8
// - 알파벳, 숫자 1바이트 
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트
// UTF16  -> wchar_t
// - 알파벳, 숫자. 한글, 한자 등 거의 문자 2바이트
// 매우 예외적인 고대문자만 4바이트 (사실상 무시해도 ㄱㅊ)

wchar_t wch = L'안'; // L붙여줌

// Escape Sequence
// 표기하기 애매한 애들 표현
// \t - 아스키코드9 - tab
// \n - 아스키코드10 - LineFeed (개행)
// \r - 아스키코드13 - CarriageReturn (커서 <<)
// \'

// 문자열
// 문자들이 열을 지어서 모여있는 것 (문자 배열?)
// 정수는 고정 길이, 문자 x
// 끝은 NULL(0)

char str1[] = { 'h','e','l','l','o' };

int main()
{
	char str2[] = { 'h','e','l','l','o' ,'\0'}; // 끝에 NULL없으면 오류
	// = char str2[] = "Hello World"; // 뒤에 자동으로 NULL

	cout << ch << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;
	// cout은 char전용

	wcout.imbue(locale("kor"));
	wcout << wch << endl;

	cout << str1 << endl;
	cout << str2 << endl;
}