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


	// 객체가 소멸되기 직전에 소멸자(destructor,dtor) CALL, ~ : 틸다
	// 생성자와는 다르게 단 하나만 존재. 객체를 정리할 필요 있을 때 코딩

	~Dog() {
		cout << name << "개님 물러가심" << '\n';
	}


	void show() {
		cout << name << " - " << age << endl;
	}
};



int main()
{
	//Dog dog{ "뎅뎅", 3 };   // 객체를 만듦과 동시에 생성자를 CALL
	Dog dog[3]{ { "Z뎅", 3 }, {"코코", 2}, {"하늘", 15} };
	//dog.show();

}

/*
Z뎅이 생성되었다
코코이 생성되었다
하늘이 생성되었다
개님 물러가심
개님 물러가심
개님 물러가심
*/