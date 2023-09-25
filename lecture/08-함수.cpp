#include <iostream>
using namespace std;

// 함수 (프로시저, 메소드, 루틴)

/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

반환타입 함수이름 ({인자타입 매개변수})
{
	함수 내용
	return ----;
}
*/

void PrintfHelloWorld()
{
	cout << "hello world" << endl;

	return;
}

void PrintNumber(int num)
{
	cout << "넘겨준 숫자는 " << num << "입니다" << endl;
}

int MultiplyBy2(int a)
{
	int result = a * 2;
	return result;
}

// f5
// f10
// f11

int main()
{
	int result = MultiplyBy2(3);
	PrintNumber(result);
}