#include <iostream>
#include <string>
#include <random>
#include <fstream>

#include "STRING.h"
using namespace std;

// [문제] "개20마리.txt" 파일에 다음과 같은 class Dog 객체 20개의 정보를 
// 연산자 <<를 사용하여 기록하였다.
// 읽어서 나이 오름차순으로 정렬한 후 화면에 출력하라

class Dog {
    int age;
    string name;

public:
    int getAge() {
        return age;
    }

    friend istream& operator>>(istream& is, Dog& d) {
        is >> d.age >> d.name;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Dog& d) {
        os << "나이: " << d.age << ", 이름: " << d.name;
        return os;
    }
};


int main()
{

    ifstream in{ "개20마리.txt" };
    if (not in) {
        cout << "파일 읽기 실패" << '\n';
        return 0;
    }

    Dog dogs[20];

    for (Dog& dog : dogs)
        in >> dog;

    qsort(dogs, sizeof(dogs) / sizeof(Dog), sizeof(Dog), [](const void* a, const void* b) {
        return ((Dog*)a)->getAge() - ((Dog*)b)->getAge();
        });

    cout << "나이 기준 오름차순 정렬한 후" << '\n';
    for (const Dog& dog : dogs)
        cout << dog << '\n';


}