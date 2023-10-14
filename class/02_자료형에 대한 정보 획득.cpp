#include <iostream>

int main()
{
	// 어떤 자료형에 대한 정보를 얻고 싶다
	// -> sizeof(), addressof(), typeid(id).name(0

	int n;

	std::cout << "int의 크기(byte) - " << sizeof(n) << std::endl;
	std::cout << "n의 주소 - " << std::addressof(n) << std::endl;
	std::cout << "n의 자료형 - " << typeid(n).name() << std::endl;

	// constexpr - 컴파일 시간에 이미 알려진 값으로 대체
	constexpr int num = std::numeric_limits<int>::max();
	std::cout << "int의 최댓값 - " << num << std::endl;
	constexpr int num2 = std::numeric_limits<int>::min();
	std::cout << "int의 최솟값 - " << num2 << std::endl;
}