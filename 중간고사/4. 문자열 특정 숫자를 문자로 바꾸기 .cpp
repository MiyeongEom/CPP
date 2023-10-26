#include <iostream>
#include <fstream>
using namespace std;

void toStar(char& c)
{
	if (isdigit(c)) {
		c = '*';
	}
}

int main()
{
	string str{ "암호 : qwer1234~!@#" };

	cout << str << endl;

	for (int i = 0; i < str.size(); ++i)
		toStar(str[i]);

	cout << str << endl;
}
