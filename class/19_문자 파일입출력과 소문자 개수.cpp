#include <iostream>
#include <format>
#include <random>
#include <fstream>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
    // [문제] 파일 "소스.cpp"에 있는 알파벳 소문자의 개수를 세서 다음과 같이 출력해라
    // a - 3
    // b - 1
    // ....
    // z - 0


    ifstream in{ "Cpp2.cpp" };
    if (not in)
        return 0;

    int count[26] = { 0 };

    char filech;

    while (in >> filech) {
        if (islower(filech)) {
            count[filech - 'a']++;
        }
    }

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        std::cout << ch << " - " << count[ch - 'a'] << std::endl;
    }
}
