#include <iostream>
using namespace std;
// 초기화 리스트

// 멤버 변수 초기화 -> 다양한 방법이 존재

// 초기화 왜 하는가?
// - 버그 예방
// - 포인터 등 주소값이 연루되어 있을 경우 

// 초기화 방법
// - 생성자 내에서 
// - 초기화 리스트 
// - C++11 문법 | 초기화 변수에 바로 초기화

// 초기화 리스트
// 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요
// 생성자 내에서 초기화 vs 초기화 리스트
// - 일반 변수는 별 차이 없음
// - 멤버 타입이 클래스인 경우 차이가 존재
// - 정의함과 동시에 초기화가 필요한 경우 (참조, const)

class Inventory {
public:

public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; }
	~Inventory() { cout << "~Inventory()" << endl; }
};

class Player {
public:
	Player() {}
	Player(int id) {}
};

// Is-A(Knight is-A player?) 기사는 플레이어다 -> 상속
// Is-A(Knight is-A inventoyr?) 기사는 인벤토리다 -> X
// Has-A (Knight Has - An inventoy?) 기사는 인벤토리를 포함하고 있다 ok -> 포함관계

class Knight:public Player {
public:
	Knight() : Player(1),_hp(100),_inventory(20), _hpRef(_hp), _hpConst(100)  //초기화 리스으
	// 선처리 영역
	// inventory()
	{
		_hp = 100;
		//_inventory = Inventory(20); //생성자 2번 호출 -> 기본 호출 + 두번째 생성자 호출
	

		// 이거 두개 불가, 할거면 초기화 리스트에
		//int& _hpRef;
		//const int _hpConst;
	}
	
public:
	int _hp;
	Inventory _inventory;

	int& _hpRef;
	const int _hpConst;
};

int main()
{
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
		cout << "Knight is Dead" << endl;

}
