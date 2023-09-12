#include <iostream>
using namespace std;

// boolean(불리언)과 실수

// bool : 참/거짓
bool isHighleve = true;
bool isPlayer = true;
bool isMale = false;

// bool은 1바이트(8비트) 정수에 불과 (0/1)
// 참과 거짓 둘 중 하나라는 힌트를 주기에 가독성이 좋다


// 실수(부동소수점)
// 1 2 3 4 int
// 3.14 0.345  
// float double(기본 세팅)

// 부동소수점
// .을 유동적으로 움직이며 표혀하는 방법

// 3.1415926535
// 1) 정규화 = 0.31415926535 * 10
// 2) 31415926535 (유효숫자) 1(지수)

// float 부호(1) 지수(8) 유효숫자(23) = 32비트 = 4바이트
// double 부호(1) 지수(11) 유효숫자(52) = 64비트 = 8바이트

float attackSpeed = 0.639f; // 4바이트
double attackSpeend2 = 123.4123; // 8바이트


// 프로그래밍 할 때 부동소수점은 근사값이라는 것을 기억

int main()
{
	
}