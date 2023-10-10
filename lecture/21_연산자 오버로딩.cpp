#include <iostream>
using namespace std;
// 연산자 오버로딩

// 연산자 vs 함수
// 연산자는 피연산자의 개수/타입이 고정되어 있음

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야 함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼
// 연산자 함수도 2가지로 구현 가능

// 멤버 연산자 함수 version
// - a op b 형태에서 왼쪽으로 기준으로 실행 (a가 클래스여야 가능. a -> 기준 피연산자)
// - 한계 : a가 클래스가 아니면 사용 못함

// 전역 연산자 함수 version
// - a op b 형태라면, a, b 모두를 연사낮 함수의 피연사자로 만들어준다.

// 그럼 무엇이 더 좋은가? -> 상황에 따라 좋은거 선택해서 해라.
// ** 대입 연산자 -> 전역 연산자 금지
// ** 복사 대입 연산자 -> 대입연산자인데 자기 자신의 참조 형태

// 기타
// 모든 연산자는 다 오버로딩 할 수 있는게 아니다.
// 모든 연산자가 다 2개 항이 있는 것 아님 ++, -- 대표적
// - 전위형 (++a) : operator++()
// - 후위형 (a++) : operator++(int)

class Position {
public:

	/* 복사생성자
	Position(const Position& arg) {

	}
	*/

	Position operator+(const Position arg) {
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}

	Position operator+(int arg) {
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg) {
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(int arg) {
		_x = arg;
		_y = arg;

		return *this;
	}

	// 복사대입연산자 -> 말 그대로 객체가 '복사'되길 원하는 특징 때문
	Position& operator=(const Position& arg) {
		_x = arg._x;
		_y = arg._y;

		return *this;
	}

	// 전위
	Position& operator++() {
		_x++;
		_y++;
		return *this;
	}

	// 후위
	Position operator++(int) {
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};

// Position pos4 = 1 + pos3;  -> 왼쪽이 클래스 아니어도 가능해짐
Position operator+ (int a, const Position &b) {
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

int main()
{
	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 0;
	pos2._y = 0;

	Position pos3 = pos + pos2;
	// pos3 = pos.operator+(pos2);

	Position pos4 = pos3 + 1;
	Position pos4 = 1 + pos3;

	bool isSame = (pos3 == pos2);

	Position pos5; //생성
	pos5 = 3; //대입

	Position pos6;
	pos6 = pos3++;
}
