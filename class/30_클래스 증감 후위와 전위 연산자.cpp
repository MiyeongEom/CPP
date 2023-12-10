#include <iostream>
#include <random>

#include "STRING.h"
using namespace std;

class INT {
	int val{};

public:
	INT() = default;
	INT(int v) : val(v) {}

	INT& operator++() {			// pre-increament, ++a
		++val;
		return *this;
	}

	INT operator++(int) {				// post-increament
		INT temp{ *this };			// 현재의 나를 저장한다
		++(*this);					// 나를 1 증가 시킨다
		return temp;				// 저장한 나를 return

	}


	friend ostream& operator<<(ostream& os, INT i) {
		return os << i.val;
	}
};


int main()
{


	INT n = 100;

	INT x = n++;

	cout << n << '\n';
}