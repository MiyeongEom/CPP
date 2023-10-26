#include <iostream>
#include <format>
#include <random>
// 정렬(Sort) - qsort
using namespace std;

int main()
{
	int a[]{ 2,4,6,8,10,9,7,5,3,1 };

	//int f(const void*, const void*);

	//qsort(a, 10, 4, f);   // f함수 본문을 알 수 없어 어떤 정렬? - 가독성 나쁨
						   // f함수를 만들어야 했나?

	// 이름 없는 함수 람다(lamda)
	qsort(a, 10, 4, [](const void* a, const void* b) {
		return *(int*)b - *(int*)a;
		});

	for (int i : a)
		cout << i << ' ';
	cout << '\n';
}

//int f(const void* a, const void* b)
//{
//	return *(int*)b - *(int*)a;
//}
