#include <bits/stdc++.h>

struct Pos
{
    int y;
    int x;

    Pos(int _y, int _x)
        : y(_y), x(_x) {}
};

struct Cell
{
    bool is_lit = 0;
    bool visited = 0;
    std::vector<Pos> switches_to;
};

const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int room_size;
Cell room[100][100];

bool is_oob(int y, int x) 
{
    return y < 0 || y >= room_size || x < 0 || x >= room_size;
}

bool is_reachable_adjacent(int y, int x)
{
    for (const auto& [dy, dx] : DIRS)
    {
        int ny = y + dy;
        int nx = x + dx;
        if (!is_oob(ny, nx) && room[ny][nx].visited)
            return 1;
    }
    return 0;
}

int count_lightable_rooms()
{
    std::queue<Pos> q({Pos(0, 0)});
    room[0][0].visited = 1;

    int n_lightable_rooms = 1;

    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        Cell& cell = room[y][x];

        for (const auto& [ny, nx] : cell.switches_to)
        {
            Cell& nx_cell = room[ny][nx];
            if (!nx_cell.is_lit && !nx_cell.visited)
            {
                if (is_reachable_adjacent(ny, nx)) // 아까 지나친걸까봐 그래.
                {
                    nx_cell.visited = 1;
                    q.push(Pos(ny, nx));
                }
                nx_cell.is_lit = 1;
                n_lightable_rooms++;
            }
        }
        
        for (const auto& [dy, dx] : DIRS)
        {
            int ny = y + dy;
            int nx = x + dx;

            if (is_oob(ny, nx))
                continue;

            Cell& nx_cell = room[ny][nx];

            if (nx_cell.is_lit && !nx_cell.visited)
            {
                nx_cell.visited = 1;
                q.push(Pos(ny, nx));
            }
        }
    }

    return n_lightable_rooms;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n_switches;
    std::cin >> room_size >> n_switches;

    for (int i = 0; i < n_switches; i++)
    {
        int s_y, s_x, d_y, d_x;
        std::cin >> s_y >> s_x >> d_y >> d_x;
        room[--s_y][--s_x].switches_to.push_back(Pos(--d_y, --d_x));
    }

    room[0][0].is_lit = 1;

    std::cout << count_lightable_rooms();
}