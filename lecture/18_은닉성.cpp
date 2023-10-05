#include <iostream>
using namespace std;
// 은닉성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 은닉성 (Data Hiding) = 캡슐화 (Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다
// 숨기는 이유 
// 1. 정말 위험하고 건드리면 안되는 경우
// 2. 다른 경로로 접근하길 원하는 경우

// 자동차 - 핸들, 페달, 엔진, 문, 각종 전기선
// 사용자 입장 사용 -> 핸들, 페달, 문
// 굳이 몰라도 됨 -> 엔진, 각종 전기선

// (멤버) 접근 지정자
// public(공개적)   proteced(보호받는)   private(개인의)
// - public : 누구한테나 공개, 실컷 사용해
// - proteced : 나의 자손들한테만 공개
// - private : 나만 사용할꺼 << class 내에서만 사용

// 상속 접근 지정자 : 다음 세대 부모의 유산을 어떻게?
// - public : 보통 얘를 많이씀, 공개적 상속(설계 그대로 상속 받음)
// - proteced : 보호받는 상속 (내 자손들한테만 물려줄거야, public -> protected, protected -> protected)
// - private : 개인적 상속(나까지만 쓰고, 자손들한테 아예 안물려줄거, public -> private, protected -> private)
// 기본은 private!!

// 엑세스 오류 -> 접근 지정자 확인

class Car {
public:
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	void TurnKey() {
		// ...
		RunEngine();
	}

protected:
	void DisassembleCar() { } // 차 분해
	void RunEngine() { } // 엔진 구동
	void ConnectCircuit() { }  // 전기선 연결

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선
};

class SuperCar : public Car {   // 상속 접근 지정자
public:
	void PushRemoteController() {
		RunEngine();
	}
};

// 캡슐화
// 연관된 데이터와 함수를 논리적으로 묶어 놓은 것

class Berserker {
public:
	// 사양 : 체력이 50이하로 떨어지면 버서커 모드발동 (강해짐)
	int GetHp() { return _hp; }

	void SetHp(int hp) {
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode() {
		cout << "매우 강해짐! " << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	SuperCar car;
	car.PushRemoteController();


}
