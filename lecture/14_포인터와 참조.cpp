#include <iostream>
using namespace std;
// 참조 vs 포인터

struct StatInfo
{
	int hp;
	int attack;
	int defense;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defense = 5;
}

void PrintInfoByP(const StatInfo* const info)
{
	if (info == nullptr)
		return;

	cout << "----------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defense << endl;
	cout << "----------------" << endl;
}

void PrintInfoByR(const StatInfo& info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defense << endl;
	cout << "----------------" << endl;
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	int number = 1;

	// 참조
	// 작동방식은 포인터와 같음
	// 새로운 바구니 느낌
	int& reference = number;

	// 그럼 왜 레퍼런스를 사용하는가?
	// 일단 포인터와 같이 8바이트
	// 주소 전달처럼 주소 값을 이용해
	// 값 전달처럼 편리하게 사용

	// 포인터 vs 참조
	// 성능 : 같음
	// 편의성 : 참조 승

	StatInfo info;

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기거나 확실하게 원본을 넘긴다는 힌트 줄 수 있음
	// 참조는 자연스럽게 모르고 지나칠 수 있음
	// ex ) 마음대로 고친다면?
	// const를 사용해 마음대로 고치는 것 막기도 함

	// 참고 포인터도 const를 사용하나 * 앞에 붙이나 뒤에 붙이나 의미가 달라짐
	// 별 뒤 : 주소값 변경 불가, 고정
	// 별 앞 : 포인터가 가리키고 있는 내용물을 바꿀 수 없음

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 어떤- 주소라는 의미라 대상이 실존하지 않을 수도 : 사칙연산 가능
	// 포인터 '없다'는 의미? : nullptr;

	// - 없는 경우도 고려해야 한다 : pointer
	// - 바뀌지 않고 읽기만 하면 된다 : const ref&
	// - 그외 일반적 ref(명시적으로 호출할 때 OUT붙이기)
	// - 단, 다른 사람이 포인터 -> 계속 포인터 사용
	ChangeInfo(OUT info);

	// pointer로 사용하던걸 참조로?
	// pointer [ 주소 (info) ]   ref,info [ 데이터 ]
	// PrintInfoByP(*pointer);

	// 참조로 사용하던걸 포인터로?
	// PrintInfoByR(&pointer);
}

