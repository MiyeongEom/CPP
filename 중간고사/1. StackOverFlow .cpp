﻿#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int num[1'000'000]{};
	cout << "프로그램 실행" << endl;
}

// 예상되는 문제 : 스택 오버플로우
// num은 지역변수에 해당하며 STACK이라는 곳에 만들어지는데
// 너무 큰 메모리의 지역변수를 선언하여 오버 플로우가 발생했다.

// 스택은 보통 제한된 크기를 가짐 
// 큰 배열을 스택에 할당하려고 하면 스택의 제한을 초과하여 오류가 발생

// 스택 오버플로우를 피하려면 동적으로 메모리를 할당하는 힙을 사용해야 함