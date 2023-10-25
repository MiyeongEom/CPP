#include <iostream>
#include <format>
#include <random>
// 정렬(Sort) - qsort
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1, 99 };

// bubble sort : 비교연산 횟수가 N^2(N*N)
// N * logN -> qsort

// qosrt
// 시작번지, 몇개야?, 한 개의 크기, <어떻게 정렬?(함수)>
// -> contiguous memory
// 정렬방법에 주소를 전달해야 하는데 어떤 타입인지 몰라서 void*로 줌

int 정렬방법(const void*, const void*);

int main()
{
	const int NUM{ 100 };
	int a[NUM];

	for (int i = 0; i < NUM; ++i)
		a[i] = uid(dre);
	
	qsort(a, NUM, sizeof(int), 정렬방법);


	for (int n : a)
		cout << format("{:8d}", n)  ;
}

int 정렬방법(const void* a, const void* b) 
{
	int* p = (int*)a;
	int* q = (int*)b;

	if (*p > *q)
		return 1;
	else if (*p < *q)
		return -1;
	return 0;
}