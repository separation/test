#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void test_case(const string& str)
{
    vector<double> coordinates{istream_iterator<double>{istringstream(str)}, istream_iterator<double>{}};
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