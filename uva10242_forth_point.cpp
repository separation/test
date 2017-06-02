#include <iostream>
#include <string>
using namespace std;

void test_case(const string& str)
{
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        test_case(line);
    }

    return 0;
}