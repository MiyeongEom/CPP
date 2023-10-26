#include <iostream>
#include <format>
#include <random>
#include <fstream>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
	// [문제] 어떤 문자를 찾기 원하는지 물어봐라
	// 파일 "소스.cpp"에 그 문자가 몇 개 있는지 알려주자
	// 이 과정을 영원히 반복하라

	ifstream in{ "Cpp2.cpp" };
	if (not in)
		return 0;

	char a;
	cout << "찾을 문자가 뭔가요 ? : ";
	cin >> a;

	char filech;
	int count{};
	while (in >> filech)
		if (a == filech)
			count++;

	cout << count;
}