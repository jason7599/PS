#include <bits/stdc++.h>

const int MAX_MAP_SIZE = 1000;

const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Pos
{
    int y;
    int x;
};

int map_height, map_width;
int rocks_durability[MAX_MAP_SIZE][MAX_MAP_SIZE];
std::vector<Pos> borders;

bool can_do(int mine_strength, int target_amount)
{
    static int visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
    static int nx_visited_id = 1;

    int visited_id = nx_visited_id++;
    int mined_amount = 0;

    std::queue<Pos> q;

    for (const Pos& pos : borders)
    {
        if (rocks_durability[pos.y][pos.x] <= mine_strength)
        {
            if (++mined_amount == target_amount)
                return 1;

            visited[pos.y][pos.x] = visited_id;
            q.push(pos);
        }
    }

    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        for (const auto& [dy, dx] : DIRS)
        {
            int ny = y + dy;
            int nx = x + dx;

            if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width)
                continue;
            
            if (visited[ny][nx] != visited_id && rocks_durability[ny][nx] <= mine_strength)
            {
                if (++mined_amount == target_amount)
                    return 1;

                visited[ny][nx] = visited_id;
                q.push({ny, nx});
            }
        }
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int target_amount;
    std::cin >> map_height >> map_width >> target_amount;

    int min_durability = INT_MAX;
    int max_durability = 0;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            int durability;
            std::cin >> durability;

            rocks_durability[y][x] = durability;

            if (!y || !x || x == map_width - 1)
            {
                min_durability = std::min(min_durability, durability);
                borders.push_back({y, x});
            }
            
            max_durability = std::max(max_durability, durability);
        }
    }

    int low = min_durability;
    int high = max_durability;

    while (low < high)
    {
        int mid = (low + high) >> 1;

        if (can_do(mid, target_amount))
            high = mid;
        else
            low = mid + 1;
    }

    std::cout << high << '\n';
}