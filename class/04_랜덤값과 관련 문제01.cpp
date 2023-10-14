#include <iostream>
#include <format>
#include <random>
// 랜덤값 생성

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 999 };

int main()
{
	int a[5];
	int max{ a[0] };

	for (int i = 0; i < 5; ++i)
		a[i] = uid(dre);

	for (int number : a) {
		std::cout << std::format("{:4d}", number);
	}
	/*
	// 가장 큰 값을 찾아라
	for (int number : a) {
		//std::cout << std::format("{:4d}", number);
		if (number > max)
			max = number;
	}

	std::cout << max << std::endl;
	*/

	// 사용자가 원하는 값이 있는지 출력하라.

	int user_number;

	std::cout << "찾을 값을 입력하세요 : ";
	std::cin >> user_number;
	bool flag{ false };

	for (int number : a) {
		if (number == user_number) {
			std::cout << "찾음";
			flag = true;
			break;
		}
	}

	if (flag == false)
		std::cout << "못찾음";

}