#include <iostream>
#include "STRING.h"
bool STRING::observer{ false };

STRING::STRING() {
	if (observer)
		std::cout << "디폴트 생성자 - " << num << ", 메모리 번지 : " << (void*)p << '\n';
}

STRING::~STRING() {
	if (observer)
		std::cout << "~STRING()- " << num << ", 메모리" << (void*)p << '\n';
	delete[]p;
}

STRING::STRING(const char* s) : num{ strlen(s) } {
	p = new char[num];
	memcpy(p, s, num);
	if (observer)
		std::cout << "STRING(char*)- " << num << ", 메모리" << (void*)p << '\n';
}

// 2023. 11. 9 복사생성자(스페셜 함수)
STRING::STRING(const STRING& other) : num(other.num) {
	p = new char[num];
	// deep copy
	memcpy(p, other.p, num);		// DMA;

	if (observer)
		std::cout << "복사생성자 - " << num << ", 메모리" << (void*)p << '\n';
}

STRING& STRING::operator=(const STRING& other) {
	// 나를 나로 할당할 이유가 없다
	if (this == &other)  // this는 주소기에 other도 주소
		return *this;

	num = other.num;
	delete[] p;
	p = new char[num];
	memcpy(p, other.p, num);

	if (observer)
		std::cout << "STRING& operator= - " << num << ", 메모리 번지 : " << (void*)p << '\n';

	return *this;
}

// C++ 11 이동생성자와 이동할당연산자 ( && - r-value reference, 이동(move)과 완벽전달(perfect forwarding)에 사용)
STRING::STRING(STRING&& other) : num{ other.num } {

	// other의 자원을 가져온다
	p = other.p;
	// other를 초기화
	other.num = 0;
	other.p = nullptr;

	if (observer)
		std::cout << " STRING(STRING&&) - " << num << ", 메모리 번지 : " << (void*)p << '\n';
}

STRING STRING::operator + (const char* str) const {
	STRING temp;			// default ctor 스페셜 함수

	temp.num = num + strlen(str);
	temp.p = new char(temp.num);

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, str, strlen(str));

	return temp;			// 여기서 복사생성자가 호출되어야 하지만 RVO가 작동된다
	// RVO(Return Value Optimization) - 반환값 최적화
}

// 2023. 11. 09 연산자 오버로딩 시작
STRING STRING::operator+(const STRING& other) const {
	STRING temp;
	temp.num = num + other.num;
	temp.p = new char[temp.num];
	memcpy(temp.p, p, num);
	memcpy(temp.p + num, other.p, other.num);

	return temp;
}

// 2023. 11. 16 Free function
STRING operator+(const char* p, const STRING& s) {
	STRING temp;
	temp.num = strlen(p) + s.num;
	temp.p = new char[temp.num];

	memcpy(temp.p, p, strlen(p));
	memcpy(temp.p + strlen(p), s.p, s.num);

	return temp;
}

// free func 용도
// const char* str = "Hello, ";
// STRING myString("world!");
// STRING result = str + myString;

// 2023. 11. 16
char STRING::operator[](int idx) const {
	return p[idx];
}

char& STRING::operator[](int idx) {
	return p[idx];
}


size_t STRING::size() const {
	return num;
}

void STRING::show() const {
	for (int i = 0; i < num; ++i)
		std::cout << p[i];
	std::cout << '\n';
}


// 2023. 11. 16
std::ostream& operator<<(std::ostream& os, const STRING& s) {
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}
