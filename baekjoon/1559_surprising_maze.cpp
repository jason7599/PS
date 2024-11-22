#include <iostream>
#include <queue>

// n e s w
const int dys[] = {-1, 0, 1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;
int doors[100][100]; // init orientation
int n_treasure; // max 8
int treasure[100][100]; // -1 if none, else treasure_id

struct State
{
    int y, x;
    unsigned char treasure_mask;
};

int solve()
{
    static int visited[100][100][4][1 << 8] = {0};
    static int n_visit_id = 1;

    std::queue<State> q({{0, 0, 0}});
    int visit_id = visited[0][0][0][0] = n_visit_id++;

    int time = 0;
    int q_size;
    while (q_size = q.size())
    {
        while (q_size--)
        {
            const auto [y, x, treasure_mask] = q.front();
            q.pop();

            if (y == map_height - 1 && x == map_width - 1
            && treasure_mask == (1 << n_treasure) - 1)
                return time;

            int ntime = (time + 1) % 4;

            if (visited[y][x][ntime][treasure_mask] != visit_id)
            {
                visited[y][x][ntime][treasure_mask] = visit_id;
                q.push({y, x, treasure_mask});
            }
            
            int d = (doors[y][x] + time) % 4;
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width)
                continue;
            
            unsigned char ntreasure_mask = treasure_mask;
            if (treasure[ny][nx] != -1)
                ntreasure_mask |= 1 << treasure[ny][nx];

            if (visited[ny][nx][ntime][ntreasure_mask] != visit_id)
            {
                visited[ny][nx][ntime][ntreasure_mask] = visit_id;
                q.push({ny, nx, ntreasure_mask});
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

    while (1)
    {
        std::cin >> map_height >> map_width;

        if (map_height + map_width == 0)
            break;

        for (int y = 0; y < map_height; y++)
        {
            for (int x = 0; x < map_width; x++)
            {
                char c;
                std::cin >> c;

                int t = 0;
                switch (c)
                {
                case 'W': t++;
                case 'S': t++;
                case 'E': t++;
                }

                doors[y][x] = t;
                treasure[y][x] = -1;
            }
        }

        std::cin >> n_treasure;
        for (int t = 0; t < n_treasure; t++)
        {
            int y, x;
            std::cin >> y >> x;
            treasure[y - 1][x - 1] = t;
        }

        std::cout << solve() << '\n';
    }
}