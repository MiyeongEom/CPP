#include <iostream>
using namespace std;
// 반복문

int main()
{
	// while 
	// 한 번만 실행이 아니라, 특정 조건까지 계속 반복해야 하는 상황
	// ex) 게임을 끌 때까지 계속 게임을 실행하라
	// ex) 목적지에 도달할 때까지 계속 이동하라

	int count = 0;

	/*
	while (count < 5)
	{
		cout << "hello world" << endl;
		count++;
	}
	*/

	/*
	// do - while
	// 무조건 한 번은 체크됨
	do
	{
		cout << "hello world" << endl;
		count++;
	} while (false);
	
	// hello world 한 번만 출력됨
	*/

	// for
	for (int cnt = 0; cnt < 5; ++cnt)
	{
		cout << "hello world" << endl;
	}

	// 정해진 횟수가 정확 -> for


	// break, continue
	// break : 무조건 현재 있는 반복문에서 빠져나감
	// continue : skip -> 예제
}