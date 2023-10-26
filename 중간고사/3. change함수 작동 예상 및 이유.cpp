#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string a{ "커피" };
	string b{ "믹스" };

	change(a, b);

	cout << a << " " << b << endl;
}


// 이 코드를 실했을 때 출력될 내용은 모른다.
// 함수 change가 내부적으로 어떻게 구현되었는지 모르기 때문이다
// change함수가 어떻게 구현되었는지에 따라 a와 b문자열의 동작이 정해진다.