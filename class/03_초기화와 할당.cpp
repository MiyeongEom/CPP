#include <iostream>
// 메모리 연속 : contiguous

int main()
{
	// 초기화와 할당(대입)

	int n = 123; // 초기화 : initialization
	n = 345; // 할당, 배정, 대입 : assignment


	// [문제] n의 값 중 가장 큰 값을 찾아 화면에 출력하라

	int a[10]{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	
	int max_value = a[0];

	for (int i = 0; i < 10; i++)
		if (a[i] > max_value)
			max_value = a[i];

	std::cout << max_value << std::endl;

}