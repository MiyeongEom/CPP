#include <iostream>
#include <format>
#include <random>
// 정렬(Sort) - qsort / 제네릭 함수
using namespace std;

int main()
{
	// [문제] alpha를 오름 차순으로 정렬하라

	char alpha[]{ "the quick brown fox jumps over the lazy log" };

	int f(const void*, const void*);
	qsort(alpha, strlen(alpha), sizeof(char), f);

	cout << alpha << ' ';
}

int f(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}