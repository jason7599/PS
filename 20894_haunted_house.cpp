#include <iostream>
#include <queue>

struct Pos
{
    int y;
    int x;
};

struct Ghost
{
    Pos pos;
    int dir;
};

const int dys[] = {0, 1, 0, -1, 0};
const int dxs[] = {1, 0, -1, 0, 0};

int map_height, map_width;
bool map_obstacles[201][201];
unsigned char unsafe_t[201][201]; // bitmasking

bool is_oob(int y, int x)
{
    return y <= 0 || y > map_height || x <= 0 || x > map_width;
}

void mark_unsafe_t(const std::vector<Ghost>& ghosts)
{
    for (const Ghost& ghost : ghosts)
    {
        for (int t = 0; t < 4; t++)
        {
            int d = (ghost.dir + t) % 4;
            int ny = ghost.pos.y + dys[d];
            int nx = ghost.pos.x + dxs[d];
            
            while (!is_oob(ny, nx) && !map_obstacles[ny][nx])
            {
                unsafe_t[ny][nx] |= 1 << t;
                ny += dys[d];
                nx += dxs[d];
            }
        }
    }
}

int get_min_escape_time(Pos start, Pos dest)
{
    static bool visited[201][201][4];
    std::queue<Pos> q;

    visited[start.y][start.x][0] = 1;
    q.push(start);

    int time = 0;
    int q_size;
    while (q_size = q.size())
    {
        while (q_size--)
        {
            int y = q.front().y;
            int x = q.front().x;
            q.pop();

            if (y == dest.y && x == dest.x)
                return time;
            
            for (int d = 0; d < 5; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (is_oob(ny, nx) || map_obstacles[ny][nx])
                    continue;

                int ntime = (time + 1) % 4;

                // WHY THE FUCK DOES ThIS NOT WORK
                // turns out the fucking stupidass & operator precedence 
                // was trumped by the == operator
                if (!visited[ny][nx][ntime]
                && ((unsafe_t[ny][nx] >> ntime) & 1) == 0)
                {
                    visited[ny][nx][ntime] = 1;
                    q.push({ny, nx});
                }
            }
        }

        time++;
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> map_height >> map_width;

    Pos start, dest;
    std::cin >> start.y >> start.x;
    std::cin >> dest.y >> dest.x;

    std::vector<Ghost> ghosts;

    for (int y = 1; y <= map_height; y++)
    {
        for (int x = 1; x <= map_width; x++)
        {
            char c;
            std::cin >> c;

            if (c == '#')
                map_obstacles[y][x] = 1;
            else if (c != '.')
            {
                map_obstacles[y][x] = 1;
                ghosts.push_back(Ghost{{y, x}, c - '0'});
            }
        }
    }

    mark_unsafe_t(ghosts);

    int ans = get_min_escape_time(start, dest);
    if (ans == -1)
        std::cout << "GG";
    else
        std::cout << ans;
}
