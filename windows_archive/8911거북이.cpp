#include <iostream>
#include <string>

using namespace std;

class Turtle
{
    const int dx[4] = { 0, 1, 0, -1 };
    const int dy[4] = { 1, 0, -1, 0 };

private:

    int dir;
    int x, x_min, x_max;
    int y, y_min, y_max;

    void updateMinMax()
    {
        if (x < x_min)
            x_min = x;
        if (x > x_max)
            x_max = x;
        if (y < y_min)
            y_min = y;
        if (y > y_max)
            y_max = y;
    }

public:

    Turtle()
    {
        reset();
    }

    void reset()
    {
        dir = 0;
        x = x_min = x_max = 0;
        y = y_min = y_max = 0;
    }

    void advance()
    {
        x += dx[dir];
        y += dy[dir];
        
        updateMinMax();
    }

    void retreat()
    {
        x -= dx[dir];
        y -= dy[dir];

        updateMinMax();
    }

    void turnLeft()
    {
        dir = (dir + 3) % 4;
    }

    void turnRight()
    {
        dir = (dir + 1) % 4;
    }

    int getAreaSize()
    {
        return (x_max - x_min) * (y_max - y_min);
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int testCaseCount;
    Turtle turtle = Turtle();

    cin >> testCaseCount;

    while (testCaseCount--)
    {
        string input;
        cin >> input;
        
        for (char c : input)
        {
            switch (c)
            {
                case 'F':
                    turtle.advance();
                    break;
                case 'L':
                    turtle.turnLeft();
                    break;
                case 'R':
                    turtle.turnRight();
                    break;
                case 'B':
                    turtle.retreat();
                    break;
            }
        }

        cout << turtle.getAreaSize() << '\n';
        turtle.reset();
    }
}