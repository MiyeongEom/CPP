﻿#include <iostream>
using namespace std;
// 호출 스택

// 함수 선언 (순서 상관X)
void Func1();
void Func2(int a, int b);
void Func3(float a);

int main()
{
	cout << "Main" << endl;
	Func1();
}

void Func1()
{
	cout << "Func1" << endl;
	//push 2
	//push 1
	//call Func2
	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;
	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}
