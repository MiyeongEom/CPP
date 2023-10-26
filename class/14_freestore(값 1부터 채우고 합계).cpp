#include <iostream>
#include <format>
#include <random>
// STACK, DATA, FreeStroe, CODE
using namespace std;

// [문제] 사용자에게 원하는 num을 입력받아 int를 num개 저장될 공간을 확보하라
// int값을 1부터 시작하는 수로 채워라 (1, 2, 3, ... , num);
// 합계를 화면에 출력하라
// 이 과정을 영원히 반복하라

// int* p의 p에 num 배열의 맨 처음 주소가 전달됨
// 지역변수에 있는데 프리스토어에 있는 내용을 포인터로 전달함

// syntatic sugar
// 꿀번역 p[0]는 항상 p + sizeof(int) * 0으로 번역됨

int main()
{
	while (true) {
		int num{};
		int sum{};
		cout << "num을 입력하세요 : ";
		cin >> num;

		int* p = new int[num];

		for (int i = 0; i < num; ++i) {
			p[i] = i + 1;
		}

		for (int i = 0; i < num; ++i)
			sum += p[i];

		cout << sum << endl;

		delete[] p;
		// int* p는 전역이라 밑의 }에서 사라짐
	}
}