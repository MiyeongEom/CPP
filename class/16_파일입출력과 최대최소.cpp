#include <iostream>
#include <format>
#include <random>
#include <fstream>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
	/*
	ofstream out{ "int만개.txt" };

	for (int i = 0; i < 1'0000; ++i) {
		out << uid(dre) << ' ';
		if (((i + 1) % 10) == 0)
			out << ' ';
	}
	*/

	ifstream in{ "int만개.txt" };

	if (not in) {
		return 0;
	}

	int num;
	int max = 0;
	int min{ numeric_limits<int>::max() };

	while (in >> num) {
		// cout << num << ' ';
		if (num > max)
			max = num;

		if (num < min)
			min = num;
	}

	cout << max << endl;
	cout << min << endl;
}