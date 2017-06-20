#include <iostream>
#include <string>
using namespace std;

class world
{
public:
    world(int x_bound, int y_bound) : m_x_bound(x_bound), m_y_bound(y_bound)
    {}

    bool exist(int x, int y) const
    {
        return x <= m_x_bound && y <= m_y_bound;
    }
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

    bool command(const world& w, char c)
    {
        switch (c)
        {
        case 'F':
            return move_forward(w);
        case 'R':
            return turn_right();
        case 'L':
            return turn_left();
        }

        return false;
    }

    friend ostream& operator<<(ostream& os, const robot& r)
    {
        os << r.m_x << " " << r.m_y << " " << r.m_direction << (r.m_alive ? "" : " LOST");
        return os;
    }

private:
    bool move_forward(const world& w)
    {
        int x = m_x, y = m_y;
        switch (m_direction)
        {
        case 'N':
            y++;
            break;
        case 'E':
            x++;
            break;
        case 'S':
            y--;
            break;
        case 'W':
            x--;
            break;
        default:
            return false;
        }

        m_alive = w.exist(x, y);
        if (m_alive)
        {
            m_x = x;
            m_y = y;
        }

        return m_alive;
    }

    bool turn_right()
    {
        switch (m_direction)
        {
        case 'N':
            m_direction = 'E';
            return true;
        case 'E':
            m_direction = 'S';
            return true;
        case 'S':
            m_direction = 'W';
            return true;
        case 'W':
            m_direction = 'N';
            return true;
        }

        return false;
    }

    bool turn_left()
    {
        switch (m_direction)
        {
        case 'N':
            m_direction = 'W';
            return true;
        case 'E':
            m_direction = 'N';
            return true;
        case 'S':
            m_direction = 'E';
            return true;
        case 'W':
            m_direction = 'S';
            return true;
        }

        return false;
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
        for (const char &c : commands)
        {
            if (!r.command(w, c)) break;
        }
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
