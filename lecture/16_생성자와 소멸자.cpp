#include <iostream>
using namespace std;
// 생성자(Constructor)와 소멸자(Destructor)
// 굉장히 특별한 함수 2종, 바로 시작과 끝을 알리는 함수
// - 시작 (탄생) : 생성자 (여러 개 가능)
// - 끝 (소멸) : 소멸자 (오직 1개)

// 암시적 생성자 (Implicit)
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 생성
// -> 우리가 명시적으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더이상 만들어지지 않음!

class Knight {  
public:
	// [1] 기본 생성자 (인자 없음)
	Knight()
	{
		cout << "생성자 호출" << endl;
		// 멤버 변수 초기화
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] 복사생성자 : 자기 자신 클래스 참조 타입을 인자로 받음
	// 똑같은 데이터를 지닌 객체가 생성되길 바란다
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] 기타 생성자
	
	// 이 중에서 인자를 1개만 받는 [기타 생성자]는
	// [타입 변환 생성자]라고 부르기도 함.
	explicit Knight(int hp) //컴파일러가 암시적으로 바꾸는걸 막음
	{
		cout << "Knight(int) 생성자 호출" << endl;
		// 멤버 변수 초기화
		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posY, int posX)
	{
		cout << "Knight(int) 생성자 호출" << endl;
		// 멤버 변수 초기화
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	// 소멸자
	~Knight()
	{
		cout << "소멸자 호출" << endl;
	}

	// 멤버 함수
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		// this->_hp = 1;  this : class 자기 자신의 포인터
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수 ( _, m_, m(대문자) )
	int _hp;
	int _attack;
	int _posX;
	int _posY;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knigt" << endl;
}

// Instantiate : 객체를 만든다
int main()
{
	Knight k1(100);
	//k1._hp = 100;
	k1._attack = 10;
	k1._posX = 0;
	k1._posY = 0;

	Knight k2(k1); // 복사생성자
	Knight k3 = k1; // 복사생성자
	
	Knight k4;  // 생성자
	k4 = k1;   // 복사

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;
	float f = num;   // 암시적 변환
	// float f = (float)num;   <- 명시적

	Knight k5;
	k5 = (Knight)1; // 컴파일러가 암시적으로 바꾸는거 막음 -> explicit

	HelloKnight((Knight)5); // -> 타입변환
}
