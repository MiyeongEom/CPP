#include <iostream>
#include <random>

#include "STRING.h"
using namespace std;

// char*로 문자열을 다루지 않는다			---> string
// []을 사용하지 않는다						---> array<타입개수>
// 자원을 사용하는 곳에 *를 사용하지 않는다 ---> 

int main()
{

	STRING s{ "C++ Programming Langauge" };


	// [문제] s가 갖고 있는 문장을 오름차순으로 정렬하라

	qsort(&s[0], s.size(), sizeof(char), [](const void* a, const void* b) {
		return *(char*)a - *(char*)b;
		});


	cout << s << '\n';
}