#include <iostream>
#include <queue>
#include <set>

using pii = std::pair<int, int>;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;
bool map_walls[1000][1000];

int area_ids[1000][1000]; // 0: unmapped;
int area_sizes[500'001];

int result[1000][1000];

bool is_oob(int y, int x)
{
    return y < 0 || y >= map_height || x < 0 || x >= map_width;
}

void map_area(int y, int x)
{
    static int n_id = 1;

    int id = area_ids[y][x] = n_id++;
    std::queue<pii> q({{y, x}});
    int size = 0;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        size++;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (!is_oob(ny, nx) && !map_walls[ny][nx] && !area_ids[ny][nx])
            {
                area_ids[ny][nx] = id;
                q.push({ny, nx});
            }
        }
    }

    area_sizes[id] = size;
}

int main()
{
    std::cin >> map_height >> map_width;
    std::vector<pii> walls_pos;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            std::cin >> c;
            if (c == '1')
            {
                map_walls[y][x] = 1;
                walls_pos.push_back({y, x});
            }
        }
    }

    for (auto [y, x] : walls_pos)
    {
        std::set<int> v_area_ids;
        int size = 1;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (!is_oob(ny, nx) && !map_walls[ny][nx])
            {
                if (!area_ids[ny][nx])
                    map_area(ny, nx);
                if (v_area_ids.find(area_ids[ny][nx]) == v_area_ids.end())
                {
                    v_area_ids.insert(area_ids[ny][nx]);
                    size += area_sizes[area_ids[ny][nx]];
                }
            }
        }

        result[y][x] = size % 10;
    }

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
            std::cout << result[y][x];
        std::cout << '\n';
    }
}