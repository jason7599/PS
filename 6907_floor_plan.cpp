#include <iostream>
#include <queue>
#include <algorithm>

int room_h, room_w;
bool room_walls[25][25];
bool visited[25][25];

const int DYS[] = {1, 0, -1, 0};
const int DXS[] = {0, 1, 0, -1};

int get_room_size(int y, int x)
{
    std::queue<std::pair<int, int>> q({{y, x}});
    visited[y][x] = 1;

    int size = 0;

    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        size++;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + DYS[d];
            int nx = x + DXS[d];

            if (ny < 0 || ny >= room_h || nx < 0 || nx >= room_w
            || room_walls[ny][nx] || visited[ny][nx]) 
                continue;

            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }

    return size;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tiles;
    std::cin >> n_tiles >> room_h >> room_w;

    for (int y = 0; y < room_h; y++)
    {
        for (int x = 0; x < room_w; x++)
        {
            char c;
            std::cin >> c;
            room_walls[y][x] = c == 'I';
        }
    }

    std::vector<int> room_sizes;

    for (int y = 0; y < room_h; y++)
    {
        for (int x = 0; x < room_w; x++)
        {
            if (room_walls[y][x] || visited[y][x])
                continue;
            
            room_sizes.push_back(get_room_size(y, x));
        }
    }

    std::sort(room_sizes.rbegin(), room_sizes.rend());

    int n_rooms_covered = 0;

    for (int room_size : room_sizes)
    {
        if (room_size > n_tiles)
            break;
        
        n_tiles -= room_size;
        n_rooms_covered++;
    }

    std::cout << n_rooms_covered << " room";
    if (n_rooms_covered != 1)
        std::cout << 's';
    std::cout << ", " << n_tiles << " square metre(s) left over";
}