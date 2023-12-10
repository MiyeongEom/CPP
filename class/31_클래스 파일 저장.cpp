#include <iostream>
#include <string>
#include <random>
#include <fstream>

#include "STRING.h"
using namespace std;

random_device rd;
default_random_engine dre{ rd() };
uniform_int_distribution uid{ 0, 999 };

// 함수란 무엇인가
// 함수이름은 무엇인가
// 호출가능한 것은 함수만이 아니다
// 1. 함수
// 2. 이름없는 함수 lambda
// 3. 함수를 가리키는 포인터 - function pointer(실시간으로 기능 전환)
// 4. 함수 호출 연산자를 오버로딩한 클래스 객체 - function object(function)


int id{};

class Dog {
	int age;
	string name;

public:
	Dog() {
		age = uid(dre);
		name = "도그-" + to_string(++id) + "호";				// 도그-1호, 도그-2호, 도그-3호
	}

	void show() const {
		cout << "나이: " << age << "살, 이름: " << name << '\n';
	}

	friend ostream& operator<<(ostream& os, const Dog& dog) {
		return os << dog.age << "\t" << dog.name << '\n';
	}


};


int main()
{
	Dog dogs[20];
	// Dog 20마리 정도를 파일에 기록하라
	ofstream out{ "개20마리.txt" };

	for (const Dog& dog : dogs)
		out << dog << '\n';
}