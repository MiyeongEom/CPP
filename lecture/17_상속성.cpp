#include <iostream>
using namespace std;
// 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// struct로는 함수를 못묶음 ㅡ-> 상속 개념
// 상속 : 부모 -> 자식에게 유산을 물려줌 (생성, 소멸자는 No)

// [  [ Player ]  ]  // 12byte
// [     Kight    ]  //  4byte

// 생성자(N) / 소멸자(1)
// Knight 생성 -> Knight의 생성자? Player 생성자?
// -> 둘다 호출

// GameObject
// - Creature : 살아 움직이는 생명체
//  + Player, Monster, Npc, Pet
// - Projectile : 투사체 같이 움직이는 애들
//  + Fireball, Arrow
// - Env : 이외의 것들

// Item
// - Weapon
//  + Sword, Bow
// - Armor
//  + Helmet, Boots, Armor
// - Consumable
//  + Potion, Sroll

class GameObject {
public:
	int _objectId;
};

class Player:public  GameObject {
public:
	Player(){
		_hp = 0;
		_attack = 0;
		_defense = 0;
		cout << "Player 기본생성자 호출" << endl; 
	}

	~Player() {
		cout << "Player 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move" << endl; }
	void Attack() { cout << "Player Attack" << endl; }
	void Die() { cout << "Player Die" << endl; }

public:
	int _hp;
	int _attack;
	int _defense;
};

class Knight :public Player {   //상속
public:
	Knight() {
		cout << "Knight 기본생성자 호출" << endl;
	}

	~Knight() {
		cout << "Knight 소멸자 호출" << endl;
	}

	//  재정의 가능 : 부모님의 유산 거부하고 새로운 이름?
	void Move() { cout << "Knight Move" << endl; }
public:
	int _stamina;
};

class Mage :public Player {
public:

public:
	int _mp;
};

int main()
{
	Knight k;

	k._hp = 100;
	k._attack = 10;
	k._defense = 5;
	k._stamina = 50;

	//k.Attack();
	//k.Move();
	//k.Die();

}
