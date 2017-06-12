#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
using namespace std;

template<size_t DIMENSION>
class point
{
public:
    friend istream& operator>>(istream& is, point<DIMENSION>& p)
    {
        p.m_coordinates = array<double, DIMENSION>{};
        return is;
    }

private:
    array<double, DIMENSION> m_coordinates;
};

void test_case(const string& str)
{
    vector<point<2>> coordinates{ istream_iterator<point<2>>{istringstream(str)}, istream_iterator<point<2>>{} };
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