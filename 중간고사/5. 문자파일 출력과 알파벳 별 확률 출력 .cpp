#include <iostream>
#include <fstream>

using namespace std;

const int N{ 1'110'000 };
char a[N];

int main()
{
	ifstream in{ "문자들.txt" };

    if (not in)
        return 0;


    for (int i = 0; i < N; ++i) {
        in >> a[i];
    }


    int count[26] = { 0 };

    for (int i = 0; i < N; ++i) {
        if (islower(a[i])) {
            count[a[i] - 'a']++;
        }
    }

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        double probability = static_cast<double>(count[ch - 'a']) / N;
        cout << ch << " - " << probability << endl;
    }
}
