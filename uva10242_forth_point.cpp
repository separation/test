#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class coordinate
{
public:
    coordinate(const string& str) : m_value(to_value(str))
    {
    }

    friend ostream& operator<<(ostream& os, const coordinate& c);

private:
    int to_value(const string& str)
    {
        return stod(str) * pow(10, (int)PRECISION);
    }

private:
    enum { PRECISION = 3 };
    int m_value;
};

ostream& operator<<(ostream& os, const coordinate& c)
{
    os << c.m_value / (int)pow(10, (int)coordinate::PRECISION) 
       << '.' 
       << setw(coordinate::PRECISION) << setfill('0') << c.m_value % (int)pow(10, (int)coordinate::PRECISION);
    return os;
}

void test_case(const string& str)
{
    vector<coordinate> coordinates;
    vector<string> tokens{ istream_iterator<string>{istringstream(str)}, istream_iterator<string>{} };
    for (const auto &token : tokens)
    {
        coordinates.push_back(coordinate(token));
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