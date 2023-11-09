#include <iostream>
using namespace std;
// 객체 지향 마무리

// 1) struct vs class
// 종이 한 장 차이. 
// struct는 public, class는 private
// -> struct는 그냥 구조체(데이터 묶음)을 표현
// -> class는 객체 지향 프로그래밍의 특징 표현

// 2) static 변수, static함수 (static = 정적 = 고정된)

class Marine
{
public:
	// 특정 마린에 종속적
	int hp;

	void TakeDamage(int damage)
	{
		hp -= damage;
	}

	static void SetAttack()
	{
		// 정적변수는 건들여도 ㄱㅊ은데
		// 종속 변수 건들이면 에러 (어떤 마린을 건들여야 하는데? -> 모호)
		s_attack = 100;
	}
	
	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack;  // 설계도상 존재
};

// 초기화 하면 data영역.
// 안하면 .bss
int Marine::s_attack = 0;

class Player
{
public:
	int id;
};

// 정적 전역 개체 (추후 공부)
static int s_global = 1;

int GenerateId()
{
	// 생명 주기 : 프로그램 시작 ~ 종료 (메모리에 항상 올라가 있음)
	// 가시 범위 : 함수 내부에서만 사용됨.

	// 정적 지역 개체
	// 데이터 영역
	static int s_id = 1;  // 계속 살아있기에 초기화는 딱 한 번만. 따라서 1, 2, 3, 4 ... 증가
	return s_id++;
}

int main()
{
	Marine m1;
	m1.hp = 35;
	m1.TakeDamage(10);

	Marine::s_attack = 6;
	// m1.s_attack = 6;

	Marine m2;
	m2.hp = 17;
	m2.TakeDamage(7);
	// m2.s_attack = 6;

	// 마린 공격력 업그레이드 완료
	Marine::s_attack = 7;
	Marine::SetAttack();
	//m1.s_attack = 7;
	//m2.s_attack = 7;

	// 스택 아님. data영역
	static int id = 10;
	int a = id;

}
