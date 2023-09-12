#include <iostream>
using namespace std;
// 주석 ctrl+k+c / ctrl+k+u

// code / data / heap / stack

// data영역 내에서 .bss / .data / .rodata

// 0이 아닌 초기화값이 있으면 .data영역
// 초기값이 0이거나, 초기값이 없는 변수라면 .bss영역


// signed : 부호존재 (+/-)
int hp = 100;
char a; // 1
short b; // 2
int c; // 4
long long d; // 8

// unsigned : 부호없음. 변수의 범위 2배(0~양수)
// 양수로만 존재할 수 있는 데이터는 unsigned?
// 무조건 이걸 사용할 건지는 의견이 갈림
// data간의 자료형 고민 무조건 해야함 !!

// 오버플로우와 언더플로우(범위보다 적을때) 조심

int main()
{
	cout << "체력이 " << hp << " 남았습니다" << endl;
}