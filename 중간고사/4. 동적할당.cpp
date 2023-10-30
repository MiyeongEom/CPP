#include <iostream>
#include <fstream>

using namespace std;

void init(int*& p, int size) {
	p = new int[size];
	for (int i = 0; i < size; ++i) {
		p[i] = 0;
	}
}

int main()
{
	int* p{ nullptr };
	init( p, 2022 );

	for (int i = 0; i < 2022; ++i)
		cout << p[i] << " ";

	cout << endl;
	delete[] p;
}
