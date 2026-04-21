#include <iostream>
#include <queue>
#include <algorithm>

int m_height, m_width;
char map[100][100];

const char c_home = 'S';
const char c_dest = 'E';
const char c_bldng = 'H';
const char c_wall = '#';

int discomfort_dec;
int discomfort_inc;

const int dys[] = {0, 1, 0, -1, 0};
const int dxs[] = {0, 0, -1, 0, 1};

struct state
{
    std::pair<int, int> pos;
    int discomfort;
};

bool& visited(const state& state)
{
    static bool _visited[100][100][100];
    return _visited[state.pos.first][state.pos.second][state.discomfort];
}

bool is_indoors(int y, int x)
{
    return map[y][x] == c_home || map[y][x] == c_bldng;
}

int solve(std::pair<int, int> home_pos)
{
    std::queue<state> q;
    q.push({home_pos, 0});
    visited({home_pos, 0}) = 1;

    int time = 0;
    size_t q_size;
    while (q_size = q.size())
    {
        while (q_size--)
        {
            auto [y, x] = q.front().pos;
            int discomfort = q.front().discomfort;
            q.pop();

            if (map[y][x] == c_dest)
                return time;

            for (int d = !is_indoors(y, x); d < 5; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (ny < 0 || ny >= m_height || nx < 0 || nx >= m_width
                || map[ny][nx] == c_wall)
                    continue;
                
                int ndiscomfort = std::max(0 ,discomfort + 
                    (is_indoors(ny, nx) ? -discomfort_dec : discomfort_inc));
                
                if (ndiscomfort >= 100)
                    continue;
            
                if (!visited({{ny, nx}, ndiscomfort}))
                {
                    visited({{ny, nx}, ndiscomfort}) = 1;
                    q.push({{ny, nx}, ndiscomfort});
                }
            }
        }
        time++;
    }

    return -1;
}

int main()
{
    std::cin >> m_height >> m_width;
    std::cin >> discomfort_dec >> discomfort_inc;

    std::pair<int, int> home_pos;

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            char c;
            std::cin >> c;
            if (c == c_home)
                home_pos = {y, x};
            map[y][x] = c;
        }
    }

    std::cout << solve(home_pos);
}