#pragma once

class STRING {
private:
	size_t num{}; //8
	char* p{};    //8

public:
	STRING();
	~STRING();
	STRING(const char* s);

	// 2023. 11. 9 복사생성자(스페셜 함수)
	STRING(const STRING& other);

	STRING& operator=(const STRING& other);

	// C++ 11 이동생성자와 이동할당연산자 ( && - r-value reference, 이동(move)과 완벽전달(perfect forwarding)에 사용)
	STRING(STRING&& other);

	// 2023. 11. 15 연산자 오버로딩
	STRING operator+(const char*) const;
	STRING operator+(const STRING&) const;


	// 2023. 11. 16 Free function
	friend STRING operator+(const char*, const STRING&);


	char operator[](int idx) const;		// 읽기 전용 []
	char& operator[](int idx);


	size_t size() const;

	void show() const;

	// 스페셜 함수를 필요할 때 관찰한다
	static bool observer;

	// 2023. 11. 16 입출력기능은 이 클래스와 밀접한 기능이다.
	// 그래서 operator<< 함수는 STRING의 멤버에 아직 이 함수도 멤버함수인 것 처럼 자유롭게
	// 접근하도록 코딩하는 것이 합리적이다. -> 이 함수를 friend로 선언한다.

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};
