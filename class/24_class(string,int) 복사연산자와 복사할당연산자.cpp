#include <iostream>
using namespace std;

class Dog {
private:
	string name;
	int age;

public:             // 멤버함수는 public으로 선언하여 클래스 바깥에서 이용할 수 있다
	Dog() :name{}, age{} { // 기본생성자
		cout << "디폴트 생성자" << '\n';
	}
	
	Dog(string name, int age) :name{ name }, age{ age } {
		cout << name << "이 생성되었다" << '\n';
	}

	~Dog() {
		cout << name << "개님 물러가심" << '\n';
	}

	// 복사 생성자 (copy constructor)
	Dog(const Dog& other) : name{ other.name }, age{ other.age } {    // & : 주소로 가져오겠다. 복사로 가져오지 않고 -> 메모리에 넣으면 클람
		cout << "복사 생성자 호출" << '\n';
	}

	// 복사 생성자와 짝이 되는 복사 할당 연산자(copy assignment operator)
	Dog& operator= (const Dog& other) {
		name = other.name;
		age = other.age;
		cout << "복사 할당 연산자 호출" << '\n';

		return *this;
	}

	void show() {
		cout << name << " - " << age << endl;
	}
};


int main()
{
	Dog dog{ "댕댕",3 };
	Dog d = dog;     // dog d는 만들어 지고 있는데. dog랑 똑같이 만들어줘.
	// 객체 d가 dog를 복사해서 생성되는 순간 - > Dog d { dog };

	Dog d2;
	d2 = dog;   // 이미 만들어진 d2를 dog와 똑같은 값이 되도록 해달라는 요청
	// copy assignment operator

}

