#include <iostream>
using namespace std;

int big(int* array, int size);

int main()
{
	int a[]{ 3,5,2,1,4 };
	int b[]{ 6, 1, 7, 10, 4, 2, 3, 8, 9, 5 };

	cout << "a에서 가장 큰 값" << big(a, 5) << endl;
	cout << "b에서 가장 큰 값" << big(b, 10) << endl;
}

int big(int* array, int size) {
	int max = numeric_limits<int>::min();
	for (int i = 0; i < size; ++i)
		if (array[i] > max)
			max = array[i];
	return max;
}