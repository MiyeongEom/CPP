#include <iostream>
#include <format>
#include <random>
// 정렬(Sort) - bubble sort
using namespace std;

default_random_engine dre;
uniform_int_distribution uid {1, 10'0000};

// 정렬되어 있으면 찾기가 좋음

void change(int&, int&);

int main()
{
	const int NUM{ 1'00 };
	int a[NUM];
	for (int i = 0; i < NUM; ++i)
		a[i] = uid(dre);

	for (int j = NUM - 1; j > 0; j--)
		for (int i = 0; i < j; ++i)
			if (a[i] > a[i + 1])
				change(a[i], a[i + 1]);

	// char key;
	// cin >> key;

	for (int n : a)
		cout << format("{:8d}", n)  ;
}

void change(int& p, int& q)
{
	int temp{ p };
	p = q;
	q = temp;
}