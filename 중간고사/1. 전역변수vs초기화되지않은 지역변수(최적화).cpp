#include <iostream>
using namespace std;

int val{ 0 };   // data

int main()
{
	int val;        // stack
	cout << val << endl;   

	// debug - 초기화하지 않아서 의미 없는 값
	// release - 지역변수 val이 초기화 되지 않아 전역변수 val을 사용 
	
	// Debug 빌드는 코드 실행 속도가 느리지만
	// 디버깅이 용이하고 컴파일 속도도 빠름
	// 코드 최적화 하지 않음

	// Release 빌드는 코드 실행 속도가 빠르고 배포하기도 용이
	// 코드 최적화 수행
}
