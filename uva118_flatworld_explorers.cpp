#include <iostream>
#include <string>
using namespace std;

int direction_to_angle(char c)
{
    switch (c)
    {
    case 'E':
        return 0;
    case 'N':
        return 90;
    case 'W':
        return 180;
    case 'S':
        return 270;
    }
    return 0;
}

char angle_to_direction(int angle)
{
    switch (angle % 360)
    {
    case 0:
        return 'E';
    case 90:
        return 'N';
    case 180:
        return 'W';
    case 270:
        return 'S';
    }
    return '\0';
}

class robot
{
public:
    robot(int x, int y, char direction): m_x(x), m_y(y), m_angle(direction_to_angle(direction))
    {
    }

private:
    int m_x;
    int m_y;
    int m_angle; // east: 0, north: 90, west: 180, south: 270 (degree)
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
