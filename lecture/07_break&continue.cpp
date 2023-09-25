#include <iostream>
using namespace std;
// 반복문

int main()
{
	int round = 1;
	int hp = 100;
	int damage = 27;

	// 무한루프 : 전투시작
	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;

		// 시스템 메시지 출력
		cout << "Round " << round << " 몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}
		
		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}
		round++;
	}


	// continue 예제

	for (int count = 1; count <= 10; count++)
	{
		bool isEven = ((count % 2) == 0);
		if (isEven)
			continue;

		cout << count << endl;
	}

}

