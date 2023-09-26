﻿#include <iostream>
using namespace std;
// 포인터

int main()
{
	// 특정 주소에 우리가 원하는 값을 넣은 셈
	// * (포인터) 는 주소를 의미한다.
	// 포린터는 8바이트 고정 크기

	int number = 1;
	int* ptr = &number;  //number의 주소를 꺼내서 넣은 것

	// 주소를 갖고 뭐하는건가?
	// 포인터가 가리키는 주소로 가서 무엇을 해라

	// 포탈을 타고 순간이동 탄다고 생각
	// *이 여러번 등장하나, 사용 시점을 구분해서 기억하자
	// - 변수 선언 (주소 저장 바구니)
	// - 사용할 때 (포탈타고 순간이동)

	int value1 = *ptr;  // 1
	*ptr = 2; // 그 값을 2로 변경해라
}
