#include <iostream>
#include <fstream>
using namespace std;

int cnt{};
void f(string);

int main()
{
	f("시험 중");
}

void f(string msg)
{
	cout << msg << " " << ++cnt;
	f(msg);
}

// 재귀 함수를 사용하여 메모리를 계속 할당하고 증가시키는 방식으로 작동함
// main함수의 f함수가 실행되며 문자열"시험 중"이 함수 f로 전달된다.
// 함수 호출은 호출 스택에 생성하는데
// 함수를 호출을 할 때마다 함수가 끝나기 전까지
// 지역/매개변수 msg 및 cnt 변수의 복사본이 저장된다.
// 함수 내에서 함수 호출은 새로운 스텍을 생성하는데 이가 반복되면서
// 스택이 추가되기만 함으로 스택 깊이가 계속 증가한다
// 이로 인해 스택의 크기를 넘어서 오버 플로우가 발생해 비정상 종료한다.
