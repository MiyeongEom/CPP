#include <iostream>
#include <fstream>
using namespace std;


const int NUM{ 1'000'000 };
int num[NUM];

int main()
{
	long long avg = 0;
	ifstream in{ "int백만개.txt" };
	if (!in) {
		cerr << "파일을 열 수 없습니다." << endl;
		return 1;
	}

	int max = 0;

	for (int i = 0; i < NUM; ++i) {
		in >> num[i];
		if (max < num[i])
			max = num[i];
	}

	for (int i : num) {
		avg += i;
	}

	double average = static_cast<double>(avg) / NUM;
	cout << "평균: " << average << endl;
	cout << "최댓값: " << max << endl;


}
