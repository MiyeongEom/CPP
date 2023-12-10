#include <iostream>
using namespace std;			

class Dog {
private:
	string name;
	int age;

public:             // 멤버함수는 public으로 선언하여 클래스 바깥에서 이용할 수 있다
	Dog(string name, int age) :name{ name }, age{ age } {
		cout << name << "이 생성되었다" << '\n';
	}

	~Dog() {
		cout << name << "개님 물러가심" << '\n';
	}

	void show() {
		cout << name << " - " << age << endl;
	}
};

Dog d3{ "ㅌ3333", 0 };

int main()
{
	cout << "메인 시작" << '\n';
	{
		Dog d{ "ㅌ", 0 };
		Dog d2{ "ㅌㅌㅌㅌ", 0 };
	}

	cout << "저장하기 전" << '\n';

}


/*
ㅌ3333이 생성되었다
메인 시작
ㅌ이 생성되었다
ㅌㅌㅌㅌ이 생성되었다
ㅌㅌㅌㅌ개님 물러가심
ㅌ개님 물러가심
저장하기 전
ㅌ3333개님 물러가심

*/

// 지역변수 -> { } 범위 안에서 생성, 소멸