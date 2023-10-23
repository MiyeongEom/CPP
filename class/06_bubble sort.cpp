#include <iostream>
#include <format>
#include <random>
// 정렬(Sort) - bubble sort

void change(int&, int&);

int main()
{
	// [문제] 
	// a를 오름차순으로 정렬하라.
	// ascending order

	int a[]{ 10, 8, 6, 4, 2, 9, 7, 5, 3, 1 };

	for (int j = 9; j > 0 ; j--)
		for (int i = 0; i < j; ++i)
			if (a[i] > a[i + 1])
				change(a[i], a[i + 1]);

	for (int n : a)
		std::cout << n << ' ';
	std::cout << std::endl;
}

void change(int& p, int& q)
{
	int temp{ p };
	p = q;
	q = temp;
}