#include <iostream>
#include <algorithm>
#include <queue>

struct Pos 
{
    int y;
    int x;
};

struct State
{
    Pos pos;
    int n_doors;

    bool operator<(const State& other) const 
    {
        return n_doors > other.n_doors;
    }
};

const int INF = 1e9;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;
char map[102][102];

const char c_empty = '.';
const char c_wall = '*';
const char c_door = '#';
const char c_prisoner = '$';

int dist_map[3][102][102];

const int d_boundaries = 0;
const int d_prisoner0 = 1;
const int d_prisoner1 = 2;

void dijkstra(Pos start, int d_idx) 
{
    std::priority_queue<State> pq;

    pq.push({start, 0});
    dist_map[d_idx][start.y][start.x] = 0;

    while (!pq.empty()) 
    {
        const auto [pos, n_doors] = pq.top();
        pq.pop();
        
        if (n_doors > dist_map[d_idx][pos.y][pos.x]) 
            continue;

        for (int d = 0; d < 4; d++) 
        {
            int ny = pos.y + dys[d];
            int nx = pos.x + dxs[d];

            if (ny < 0 || ny > map_height + 1 || nx < 0 || nx > map_width + 1
            ||  map[ny][nx] == c_wall)
                continue;

            int nx_cost = n_doors + (map[ny][nx] == c_door);

            if (nx_cost < dist_map[d_idx][ny][nx]) 
            {
                dist_map[d_idx][ny][nx] = nx_cost;
                pq.push({{ny, nx}, nx_cost});
            }
        }
    }
}

int main() 
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::cin >> map_height >> map_width;

        for (int d_idx = 0; d_idx < 3; d_idx++)
        {
            for (int y = 0; y <= map_height + 1; y++)
            {
                for (int x = 0; x <= map_width + 1; x++)
                    dist_map[d_idx][y][x] = INF;
            }
        }

        std::vector<Pos> prisoners;

        for (int y = 0; y <= map_height + 1; y++) 
        {
            for (int x = 0; x <= map_width + 1; x++) 
            {
                if (!y || y == map_height + 1 || !x || x == map_width + 1)
                {
                    map[y][x] = c_empty;
                    continue;
                }

                char c;
                std::cin >> c;

                if (c == c_prisoner)
                {
                    prisoners.push_back({y, x});
                    c = c_empty;
                }

                map[y][x] = c;
            }
        }

        dijkstra({0, 0}, d_boundaries);
        dijkstra(prisoners[0], d_prisoner0);
        dijkstra(prisoners[1], d_prisoner1);

        int min_cost = INF;
        
        for (int y = 0; y <= map_height + 1; y++)
        {
            for (int x = 0; x <= map_width + 1; x++)
            {
                if (map[y][x] == c_wall)
                fucked:
                    continue;

                int cost = map[y][x] == c_door ? -2 : 0;

                for (int d_idx = 0; d_idx < 3; d_idx++)
                {
                    if (dist_map[d_idx][y][x] == INF)
                        goto fucked;
                    cost += dist_map[d_idx][y][x];
                }

                min_cost = std::min(min_cost, cost);
            }
        }

        std::cout << min_cost << '\n';
    }

    return 0;
}