#include <iostream>
using namespace std;

void change(char*& a, char*& b);

int main()
{
	char* p = const_cast<char*>("10월");
	char* q = const_cast<char*>("2022년");

	change(p, q);

	cout << p << q << endl;
}

void change(char*& a, char*& b) {
	char* temp = a;
	a = b;
	b = temp;
}

/*
void change(char*& a, char*& b) {
	char* temp = a;
	a = b;
	b = temp;
}
*/