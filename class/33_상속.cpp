#include <iostream>
#include <string>
#include <random>
#include <fstream>

#include "STRING.h"
using namespace std;

//[문제]Animal 과 Dog을 상속관계로 표현
class Animal {
    int age;

public:
    Animal() {
        cout << "Animal 기본생성" << '\n';
    }

    Animal(int n) : age(n) {

    }

    ~Animal() {
        cout << "Animal 소멸자" << '\n';
    }

    void move() {
        cout << age << "살-움직인다" << '\n';
    }
};

class Dog : public Animal {
    string name;
public:
    Dog() {
        cout << "Dog 기본생성" << '\n';
    }

    Dog(int n) : Animal{ n } {

    }

    ~Dog() {
        cout << "Dog 소멸자" << '\n';
    }
};



int main()
{

    Dog dog{ 10 };
    cout << sizeof(dog);
    dog.move();

}