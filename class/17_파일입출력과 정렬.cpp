#include <iostream>
#include <format>
#include <random>
#include <fstream>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
	ifstream in{ "int만개.txt" };

	if (not in) {
		return 0;
	}

	int num[1'0000];

	for (int i = 0; i < 1'0000; ++i)
		in >> num[i];

	qsort(num, 1'0000, sizeof(int), [](const void* a, const void* b){ 
		return *(int*)a - *(int*)b;
		});

	for (int a : num)
		cout << a << " ";
}