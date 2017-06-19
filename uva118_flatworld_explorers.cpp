#include <iostream>
using namespace std;

class world
{
public:
    world(int x_bound, int y_bound) : m_x_bound(x_bound), m_y_bound(y_bound)
    {}

private:
    int m_x_bound;
    int m_y_bound;
};
int main()
{
    int x_bound = 0, y_bound = 0;
    cin >> x_bound >> y_bound;
    world my_world(x_bound, y_bound);
    return 0;
}
