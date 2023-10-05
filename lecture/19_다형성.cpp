#include <iostream>
using namespace std;
// 다형성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 다형성 (Polymorphism = Poly + morph) = 겉은 같은데, 기능이 다르게 동작
// - 오버로딩 : 함수 중복 정의 = 함수 이름 재사용
// - 오버라이딩  : 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩 = 묶는다
// - 정적 바인딩 : 컴파일 시점에 결정
// - 동적 바인딩 : 실행 시점에 결정 (면접 단골질문)

// 일반 함수는 정적 바인딩 사용
// 동적바인딩을 원하면 -> 가상 함수 사용 (Virtual function)

// 순수 가상함수 ' = 0 '
// 구현은 없고 인터페이스만 전달하는 경우
// 이게 하나 이상 포함되면 추상 클래스로 간주
// - 직접적으로 객체를 만들 수 없게 됨
// - 자식에서 재정의

class Player {
public:
	void Move() { cout << "Move Player!" << endl; }
	// void Move(int n) { cout << "Move Player (int) !" << endl; }   : 오버로딩
	virtual void VMove() { cout << "Move Player!" << endl; }   // 동적 바인딩
	virtual void VAttack() = 0;

public:
	int _hp;
};

class Knight :public Player {
public:
	void Move() { cout << "Move Knight!" << endl; }  // 오버라이딩
	// 가상 함수는 재정의해도 가상 함수.
	virtual void VMove() { cout << "Move Knight!" << endl; }   // 동적 바인딩
	virtual void VAttack(){cout << "Attack Knight!" << endl; }

public:
	int _stamina;
};

class Mage :public Player {
public:

public:
	int _mp;
};

void MovePlayer(Player* player) {  // 정적바인딩
	player->VMove();
}

int main()
{
	//Player p;
	//MovePlayer(&p);   // 플레이어는 플레이어다 : YES
	// MoveKnight(&p);   // 플레이어는 기사다 : NO

	Knight k;
	//MoveKnight(&k);   // 기사는 기사다 : YES
	MovePlayer(&k);  // 기사는 플레이어다 : YES

}
