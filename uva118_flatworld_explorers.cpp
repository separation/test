#include <iostream>
using namespace std;

class robot_commander
{
public:
    robot_commander(int x, int y) : m_x_bound(x), m_y_bound(y)
    {
    }

private:
    int m_x_bound;
    int m_y_bound;
};
int main()
{
    int x = 0, y = 0;
    cin >> x >> y;
    robot_commander commander(x, y);
    return 0;
}
