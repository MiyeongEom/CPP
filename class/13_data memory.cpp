#include <iostream>
#include <format>
#include <random>
// STACK, DATA, FreeStroe, CODE
using namespace std;

// [문제] DATA에 저장할 수 있는 최대 크기는?  : 2기가가 넘어가는 데이터영역을 허용하지 않는 군
char c[1'000'000'000]{ 1,2,3 };    // 1기가

// 디폴트와 값을 주는 경우
// 한 개라도 값을 줘서 초기화하는 경우

int main()
{

	cout << (int)c[0] << endl;
	cout << (int)c[1] << endl;

}