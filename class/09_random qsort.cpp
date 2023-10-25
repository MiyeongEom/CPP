#include <iostream>
#include <format>
#include <random>
// 정렬(Sort) - qsort
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1, 99'9999 };

int rule(const void*, const void*);

const int NUM{ 100'0000 };
int a[NUM];

int main()
{
	// [문제] int 100만개를 랜덤값 생성
	// 이를 오름차순으로 정렬하라

	// const int NUM{ 100'0000 };
	// int a[NUM];

	for (int& num : a) {
		num = uid(dre);
	}

	qsort(a, NUM, sizeof(int), rule);

	for (int i = 0; i < 10; ++i)
		cout << a[i] << ' ';

	cout << endl;

	for (int i = 0; i < 10; ++i)
		cout << a[NUM - 1 - i] << ' ';

}

int rule(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}