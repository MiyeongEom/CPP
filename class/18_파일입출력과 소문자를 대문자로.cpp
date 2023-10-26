#include <iostream>
#include <format>
#include <random>
#include <fstream>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid;

int main()
{
    // [문제] 파일 "Cpp2.cpp"에 있는 알파벳 소문자를 모두 대문자로 바꿔
    // "소스대문자.txt"에 기록하시오

    ifstream in{ "Cpp2.cpp" };
    ofstream out{ "소스대문자.txt" };

    if (not in)
        return 0;

    int count[26]{ };

    char filech;
    in >> noskipws; //공백포함
    while (in >> filech) {
        if (islower(filech)) {
            filech = toupper(filech);
        }

        out.put(filech);
    }

}

// qqq