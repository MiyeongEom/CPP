#include <iostream>
using namespace std;
// 포인터 연산

// 주소연산자(&)
// 산술연산자 (+, -)
// 간접연산자 (*)
// 간접 멤버 연산자(->)

struct Player
{
	int hp;
	int damage;
};

int main()
{
	int number = 1;
	
	// 1. 주소연산자 : 해당 변수의 주소를 알려줘
	// + 해당 변수 타입에 따라 타입* 반환
	int* p = &number;
	
	// 2. 산술 연산자 (+, -)
	number += 1;   // 1증가

	// int *
	// * : 포인터 타입이네 -> (8바이트) 주소를 담는 바구니
	// int : 주소를 따라가면 int(4바이트) 바구니
	
	// [!] 포인터에서 +나 - 등 산술 연산으로 1을 더하거나 빼면
	// 정말 그 숫자를 더하고 뺴라는 의미가 아니라
	// 한 번에 타입 크기만큼 이동하라는 의미
	// 즉 n을 더하면 바구니 n개 이동해라 

	p += 1;  // 4증가(?)

	// 3. 간접 연산자
	// 해당 주소로 이동
	number = 3;
	*p = 3;

	// 4.간접 멤버 연산자
	// * 간접 연산자 + 구조체의 특징 멤버를 다룰 때 사용

	Player py;
	py.hp = 100;
	py.damage = 10;


	Player* playPtr = &py;
	playPtr->hp = 200; //  (*playPtr).hp = 200;
	playPtr->damage = 200; // (*playPtr).damage = 10;
	

}
