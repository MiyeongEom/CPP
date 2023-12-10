#include <iostream>
#include <random>
using namespace std;		

default_random_engine dre;
uniform_int_distribution uid(-100, 100);

struct Point2D {
	int x;
	int y;

	void show() {
		cout << "(" << x << ", " << y << ")" << '\n';
	}
};

// [문제] 2차원 점 100개를 생성하라
// 좌표값은 [-100, 100] 랜덤값으로 설정
// 원점에서 폭탄이 터진다 (반경 20까지 영향을 받는다)
// 폭탄의 영향을 받는 점을 화면에 출력하라


int main()
{
	Point2D ps[100];

	for (int i = 0; i < 100; ++i) {

		ps[i].y = uid(dre);
		ps[i].x = uid(dre);
		cout << "(" << ps[i].x << ", " << ps[i].y << ")" << '\n';
	}


	cout << '\n' << "펑!!" << '\n' << "이 중 폭탄이 터진 점들은" << endl;

	for (Point2D& p : ps) {

		if (sqrt(p.x * p.x + p.y * p.y) <= 20) {
			p.show();
		}
	}

}
