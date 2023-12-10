#include <iostream>
#include <random>
using namespace std;

// [문제] std::string은 c언어의 char*을 대체한다
// 이와 유사한 기능을 하는 STRING을 직접 코딩해 사용자 정의 자료형을 더 깊게 이해한다.
// main이 문제 없이 실행되도록 하라.

class STRING {
private:
	size_t num; //8
	char* p;    //8

public:
	STRING() {
		cout << "디폴트 생성자 - " << num << ", 메모리 번지 : " << (void*)p << '\n';
	}

	STRING(const char* s) : num{ strlen(s) } {
		p = new char[num];
		memcpy(p, s, num);

		cout << "STRING(char*)- " << num << ", 메모리" << (void*)p << '\n';
	}

	// 2023. 11. 9 복사생성자(스페셜 함수)
	STRING(const STRING& other) : num(other.num) {
		p = new char[num];
		// deep copy
		memcpy(p, other.p, num);		// DMA;

		cout << "복사생성자 - " << num << ", 메모리" << (void*)p << '\n';
	}

	STRING& operator=(const STRING& other) {
		// 나를 나로 할당할 이유가 없다
		if (this == &other)  // this는 주소기에 other도 주소
			return *this;

		num = other.num;
		delete[] p;
		p = new char[num];
		memcpy(p, other.p, num);

		cout << "STRING& operator= - " << num << ", 메모리 번지 : " << (void*)p << '\n';

		return *this;
	}

	// C++ 11 이동생성자와 이동할당연산자 ( && - r-value reference, 이동(move)과 완벽전달(perfect forwarding)에 사용)
	STRING(STRING&& other) : num{ other.num } {

		// other의 자원을 가져온다
		p = other.p;
		// other를 초기화
		other.num = 0;
		other.p = nullptr;

		cout << " STRING(STRING&&) - " << num << ", 메모리 번지 : " << (void*)p << '\n';
	}

	// 2023. 11. 09 연산자 오버로딩 시작
	STRING operator+(const STRING& other) {
		STRING temp;
		temp.num = num + other.num;
		temp.p = new char[temp.num];
		memcpy(temp.p, p, num);
		memcpy(temp.p + num, other.p, other.num);

		return temp;
	}

	~STRING() {
		cout << "~STRING()- " << num << ", 메모리" << (void*)p << '\n';
		delete[]p;
	}

	size_t size() const {
		return num;
	}

	void show() const {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}

};

int main()
{
	// t = t = t = t;  매우 비효율적이며 해서는 안될 동작 -> 복사할당연산자에 반영
	// STRING t = move(s); -> 이동

	STRING s{ "스트링" };
	STRING t{ "입니다" };

	STRING u = s + t;     // STRING u = s.operator+(t);

	u.show();

}