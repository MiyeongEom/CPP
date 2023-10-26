#include <iostream>
#include <format>
#include <random>
#include <fstream>
// STACK, DATA, FreeStroe, CODE
using namespace std;

int main()
{

	//int cnt{};
	//while(true){
	//
	//	new char[1'000'000'000];
	//	cout << ++cnt << "기가 하당됨" << endl;
	//}

	// 파일 생성

	// ofstream out{ "int100개.txt" };   // STACK, 264byte
	// for (int i = 0; i < 100; ++i)
	//	out << i << ' ';

	// 파일 읽기
	ifstream in{ "int100개.txt" };

	if (!in)
		return 0;

	/*
	for (int i = 0; i < 100; ++i) {
		int a;
		in >> a;
		cout << a << ' ';
	}
	*/
	
	// 몇 개인지 모를때
	int num;
	while (in >> num)  //in에서 num으로 읽어올 in값이 있는 한
		cout << num << ' ';
	cout << endl;
	
}