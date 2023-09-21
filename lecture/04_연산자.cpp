#include <iostream>
using namespace std;

// 데이터 연산
// 데이터 가공

int a = 1;
int b = 2;

bool isSame;
bool isDiff;
bool isGreater;
bool isSmaller;
bool test;

int hp = 100;
bool isInvincible = true;

unsigned char flag; //부호를 없애야 >>를 하더라도 부호비트가 딸려오지 X

// 한 번 정해지면 절대 바뀌지 않는 값 : const
// 메모리 할당 안될 수도, 될 수도 -> 컴파일러 마음
// 다만 이걸 메인 안에서 쓸 경우 스택영역에서 만듦
const int Air = 0;
const int Stun = 1;
const int PolyMorph = 2;
const int Invincible = 3;

// 전역변수 -> 데이터 영역


int main()
{
	int c = 3; // 스택영역
#pragma region 산술연산
	// 산술 연산자

	// 대입연산
	// a를 b에 대입하고 b 반환
	// -> b라는 바구니 안에 있는 값을 a라는 바구니 안에다 복사
	a = b;

	// 사칙연산
	// 데미지 계산, 체력 깎기, 루프문에서 +1

	a = b + 3; // add
	a = b - 3; // sub
	a = b * 3; // mul
	a = b / 3; // 나눗셈 div
	a = b % 3; // 나머지 dic

	a += 3;
	a -= 3;
	a *= 3;
	a /= 3;
	a %= 3;

	// 증감 연산자
	a++;
	++a;
	a--;
	--a;

#pragma endregion

#pragma region 비교연산

	// 언제?
	// ex) 체력이 0되면 사망, 체력이 30%이하면 궁극기 발동 등
	// 즉 특정 조건이 되면 어떠한 event

	// a == b : a와 b가 같은가?
	// 같으면 1, 다르면 0
	isSame = (a == b);

	// a != b : a와 b가 다른가?
    // 다르면 1, 같으면 0
	isDiff = (a == b);

	// a > b . a >= b
	isGreater = (a > b);

	// a < b . a <= b
	isSmaller = (a < b);

#pragma endregion

#pragma region 논리연산
	// 언제 필요한가? 조건에 대한 논리적 사고가 필요
	// ex) 로그인할 때 아이디도 같고 + 비번도 같아야 한다 (동시에 만족해야 함)
	// ex) 길드 마스터이거나 운영자 계정이면 길드 해산가능 (OR)

	// ! not
	test = !isSame; // isSame 값을 반대로, isDiff와 같은 의미

	// && end
	// a && b -> 둘다 1이면 1, 그외 0 (두 조건 만족해야함)
	test = (hp <= 0 && isInvincible == false);; //죽음

	// || or
	// a || b -> 둘 중 하나라도 1이면 1 (둘다 0이면 0)
	test = (hp > 0 || isInvincible == true); //생존

#pragma endregion

#pragma region 비트연산
	// 언제 필요한가?
	// ex) 비트 단위의 조작이 필요할 때 
	// 대표적으로 BitFlag

	// - bitwise not
	// 단일 숫자의 모든 비트를 대상으로 0을 1로, 1을 0으로 바꿈

	// & bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로 and를 한다

	// | bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로 or를 한다

	// ^ bitwise wor
	// 두 숫자의 모든 비트 쌍을 대상으로 xor한다

	// << 비트 좌측 이동
	// 비트열을 n만큼 왼쪽으로 이동
	// 왼쪽의 넘치는 n개의 비트는 버림, 새로 생성되는 n개의 비트는 0
	// *2를 할 때 자주 보이는 패턴

	// >> 비트 우측 이동
	// 비트를 n만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 n개의 비트는 버림
	// 왼쪽 생성되는 n개의 비트는
	// - 부호가 존재할 경우 부호 비트를 따라감
	// - 아니면 0

	// Ob0000 [무적][변이][스턴][공중부양]
	
	// 무적상태로 만든다
	flag = (1 << Invincible);

	// 변이 상태
	flag |= (1 << PolyMorph);

	// 무적인지 확인하고 싶다?
	// bitmask
	bool invincible = ((flag& (1 << Invincible)) != 0);

	// 무적이거나 스턴 상태인지 확인하고 싶다
	bool stunOrInvincible = ((flag & 0b1010) != 0);

#pragma endregion

}