#include <iostream>
#include <random>
using namespace std;

// [문제] 나는 MemoryMonster다. 생성 시 랜덤한 수의 int 값을 전달받아 그 수 만큼 int 메모리를 생성
// Free-Store에 할당한 후 모든 값을 1부터 시작하는 정수로 채우자.
// 다음 코드가 문제 없이 실행되도록 코딩하자

default_random_engine dre;
uniform_int_distribution uid(1, 9999);

class MemoryMonster {
	int size;
	int* p;
public:
	MemoryMonster(int n) :size(n) {
		p = new int[n];
		for (int i = 0; i < n; ++i)
			p[i] = uid(dre);
		cout << "생성(int) - " << size << ". [0] - " << p[0] << '\n';
	};

	~MemoryMonster() {
		cout << "소멸직전 - " << size << ". [0] - " << p[0] << '\n';
		delete[] p;
	}

	// 복사생설자
	MemoryMonster(const MemoryMonster& other) : size(other.size) {
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = other.p[i];

		cout << "복사완료 - " << size << ". [0] - " << p[0] << '\n';

	}

	//interface
	int getSize() const {
		return size;
	}

	void show() const const const {
		cout << "내가 관리하는 int의 수 - " << size << ". [0] - " << p[0] << '\n';
	}
};



int main()
{
	MemoryMonster a[3]{ 1,3,5 };		// MemoryMonster에 int 100개


	cout << '\n' << '\n' << '\n';

	for (const MemoryMonster& mon : a)
		mon.show();

	cout << '\n' << '\n' << '\n';


}


