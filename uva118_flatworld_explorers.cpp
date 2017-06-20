#include <iostream>
#include <string>
using namespace std;

class world
{
public:
    world(int x, int y) : m_x_bound(x), m_y_bound(y)
    {}

    bool is_outside(int x, int y) const
    {
        return x > m_x_bound || y > m_y_bound;
    }

private:
    int m_x_bound;
    int m_y_bound;
};
int main()
{
    int x = 0, y = 0;
    cin >> x >> y;
    world my_world(x, y);

    char direction = '\0'; string commands;
    while (cin >> x >> y >> direction >> commands)
    {
        my_world.is_outside(x, y);
    }

    return 0;
}
