#include <iostream>

int width;
int pos;
int dir;

void draw()
{
    std::cout << '\n';
    for (int i = 1; i <= width; i++)
        std::cout << (i == pos);
    std::cout << '\n';
}

void update()
{
    int npos = pos + dir;
    if (npos < 1)
        npos = -npos + 2;
    npos = (npos - 1) % (2 * width - 2) + 1;
    if (npos > width)
    {
        npos = 2 * width - npos;
        dir = -1;
    }
    else
        dir = 1;
    
    pos = npos;
}

void update2()
{
    // Calculate the effective new position in an infinite line
    int distance = dir;
    int new_pos = pos + distance;

    // Calculate the cycle length for bouncing
    int cycle_length = 2 * (width - 1);

    // Map the position to the cycle using modulo
    new_pos = (new_pos - 1) % cycle_length + 1;

    // Handle the bounce in bounds
    if (new_pos > width)
    {
        pos = 2 * width - new_pos; // Reflect within bounds
        dir = -1; // Reverse direction
    }
    else if (new_pos < 1)
    {
        pos = 2 - new_pos; // Reflect within bounds
        dir = 1; // Reverse direction
    }
    else
    {
        pos = new_pos; // Within bounds, update position directly
    }
}

int main()
{
    width = 5;
    pos = 2;
    dir = -1;

    draw();

    int iter = 12;
    while (iter--)
    {
        update2();
        draw();
    }
}