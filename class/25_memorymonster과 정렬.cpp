#include <iostream>
using namespace std;

// [문제] 나는 MemoryMonster다. 생성 시 int값을 받아 그 값에 해당하는 메모리를
// Free-Store에 할당한 후 모든 값을 1부터 시작하는 정수로 채우자.
// 다음 코드가 문제 없이 실행되도록 코딩하자

class MemoryMonster {
	int size;
	int* p;
public:
	MemoryMonster(int n) :size(n) {
		p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = i + 1;
	};

	~MemoryMonster() {
		delete[] p;
	};

	//interface
	int getSize() const {
		return size;
	}

	void show() const const const {
		cout << "메모리 몬스터" << size << ",  첫 원소값 - " << p[0] << '\n';
	}
};



int main()
{
	MemoryMonster mons[]{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// mons를 size기준 오름차순으로 정렬해라

	qsort(mons, sizeof(mons) / sizeof(MemoryMonster), sizeof(MemoryMonster),
		[](const void* a, const void* b) {
			return ((MemoryMonster*)a)->getSize() - ((MemoryMonster*)b)->getSize();
		});

	for (const MemoryMonster& mon : mons)   // & 없으면 복사되서 안됨
		mon.show();

}


