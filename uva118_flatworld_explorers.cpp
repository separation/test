#include <iostream>
#include <string>
using namespace std;

class robot
{
public:
    robot(int x, int y, char direction): m_x(x), m_y(y), m_direction(direction)
    {
    }

private:
    int m_x;
    int m_y;
    char m_direction;
};
class robot_commander
{
public:
    robot_commander(int x, int y) : m_x_bound(x), m_y_bound(y)
    {
    }

    bool send_robot(robot& r, const string& commands)
    {
        return true;
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

    char direction = '\0';
    string commands;
    while(cin >> x >> y >> direction >> commands)
    {
        robot r(x, y, direction);
        if(commander.send_robot(r, commands))
        {
            // TODO: output robot position
        }
        else
        {
            // TODO: output robot position and lost
        }
    }
    return 0;
}
