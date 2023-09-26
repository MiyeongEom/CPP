#include <iostream>
using namespace std;
// 함수 오버로딩 (중복 정의) : 함수 이름의 재사용
// - 매개변수가 다르다거나
// - 매개변수 타입이 다르다

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
}

// 기본 인자값 
void SetPlayerInfo(int hp, int mp, int attack, int guildld = 0)
{
	// 길드 기본 값을 0으로 하겠다
	// 단 세팅하려면 마지막에서 하기
}

// 스택 오버플로우
int factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * factorial(n - 1);
}

int main()
{
	float result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10);

	cout << factorial(5) << endl;
}
