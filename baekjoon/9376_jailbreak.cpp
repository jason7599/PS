#include <iostream>
#include <queue>

using pii = std::pair<int,int>;

int m_height, m_width;
char map[100][100];

const char t_prisoner = '$';
const char t_wall = '*';
const char t_door = '#';
const char t_empty = '.';

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::cin >> m_height >> m_width;
        pii p0, p1;
        bool p0f = 0;

        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                char c;
                std::cin >> c;
                if (c == t_prisoner)
                {
                    if (!p0f)
                    {
                        p0 = {y, x};
                        p0f = 1;
                    }
                    else
                        p1 = {y, x};
                    
                    c = t_empty;
                }
                map[y][x] = c;
            }
        }
    }
}