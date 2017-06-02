#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

class coordinate
{
public:
    coordinate(const string& str) : m_value(to_value(str))
    {
    }

private:
    int to_value(const string& str)
    {
        return stod(str) * pow(10, (int)PRECISION);
    }

private:
    enum { PRECISION = 3 };
    int m_value;
};

void test_case(const string& str)
{
    istringstream is(str);
    string s;
    while (is >> s)
    {
        coordinate c(s);
    }

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