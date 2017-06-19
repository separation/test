#include <iostream>
#include <string>
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

class robot
{
public:
    robot(int x, int y, char direction) : m_x(x), m_y(y), m_direction(direction), m_alive(true)
    {
    }

    friend ostream& operator<<(ostream& os, const robot& r)
    {
        os << r.m_x << " " << r.m_y << " " << r.m_direction << (r.m_alive ? "" : " LOST");
        return os;
    }

private:
    int m_x;
    int m_y;
    char m_direction;
    bool m_alive;
};

class robot_commander
{
public:
    void send_robot(const world& w, const string& commands, robot& r)
    {
    }
};

int main()
{
    int x_bound = 0, y_bound = 0;
    cin >> x_bound >> y_bound;
    world my_world(x_bound, y_bound);

    char direction = '\0';
    string commands;
    int x = 0, y = 0;
    robot_commander commander;
    while (cin >> x >> y >> direction >> commands)
    {
        robot my_robot(x, y, direction);
        commander.send_robot(my_world, commands, my_robot);
        cout << my_robot << endl;
    }
    return 0;
}
