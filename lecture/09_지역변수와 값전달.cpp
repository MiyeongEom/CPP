#include <iostream>
using namespace std;
// 지역변수와 값 전달

void increaseHp(int* hp)
{
	// hp = hp + 1;
	// 왜 결과가 반영이 안될까?
	// 이 hp(매개변수)와 main(지역변수)함수의 hp는 다름
	*hp = *hp + 1;
	// 포인터 개념 필요
}

// 함수 생성 순서의 역으로 소멸
// [매개변수][RET][지역변수] [매개변수][RET][지역변수]

int main()
{
	int hp = 1; //스택

	cout << "Increase 호출 전 - " << hp << endl;
	increaseHp(&hp); // hp가 복사되어 전달
	cout << "Increase 호출 후 - " << hp << endl;
}