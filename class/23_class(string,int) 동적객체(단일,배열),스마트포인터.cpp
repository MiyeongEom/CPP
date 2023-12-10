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


int main()
{
	//Dog* p = new Dog{ "댕", 10 };  // 소멸되지 않고 메모리에 남아있음
	//delete p;
	
	//Dog* p = new Dog[2]{ { "댕", 10 },{"하늘", 15} };
	//delete[] p;

	{
		//unique_ptr<Dog> p{ new Dog{"댕", 10} };   // 스마트 포인터, 알아서 사라짐. RAII
	  // unique_ptr<Dog> p{ new Dog[3]{{"댕", 10}, {"하늘", 11}, {"바다",12}} };  -> X, 이 스마트 포인터는 한 번에 하나의 객체에 대한 소유권
	}

	std::unique_ptr<Dog[]> p{ new Dog[3]{{"댕", 10}, {"하늘", 11}, {"바다", 12}} };

	for (int i = 0; i < 3; ++i) {
		p[i].show();
	}

	cout << "지역 끝" << '\n';
}

