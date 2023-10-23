#include <iostream>
#include <format>

// C++은 같은 이름이 함수가 있어도 된다
// 함수 전달 인자를 보고 구분가능한 경우에만.
// --> function overloading

void change(int*, int*);    // 함수 선언문
void change(int&, int&);

int main()
{
	int a{ 1 };
	int b{ 2 };

	// [문제] 함수를 호출해서 a와 b의 값을 바꿔라
	change(a, b);

	std::cout << a << ", " << b << std::endl;
}

// main에서 번지(&)로 전달할 경우
void change(int* p, int* q)
{
	int temp{*p};
	*p = *q;
	*q = temp;
}

// a와 b를 레퍼런스로 받아서 출력
void change(int& p, int& q)
{
	int temp{ p };
	p = q;
	q = temp;
}