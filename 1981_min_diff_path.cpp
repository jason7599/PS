#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

int map_size, map[100][100];

const int moves[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

inline bool in_range(int x, int low, int high)
{
    return low <= x && x <= high;
}

bool exists_path(int low, int high)
{
    static int visited[100][100];
    static int n_visit_id = 1;

    if (!in_range(map[0][0], low, high))
        return 0;
    
    int visit_id = visited[0][0] = n_visit_id++;
    std::queue<std::pair<int, int>> q({{0, 0}});

    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        if (y == map_size - 1 && x == map_size - 1)
            return 1;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + moves[d][0];
            int nx = x + moves[d][1];

            if (!in_range(ny, 0, map_size - 1)
            || !in_range(nx, 0, map_size - 1)
            || !in_range(map[ny][nx], low, high)
            || visited[ny][nx] == visit_id)
                continue;
            
            visited[ny][nx] = visit_id;
            q.push({ny, nx});
        }
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> map_size;
    std::set<int> elems_set;
    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            std::cin >> map[y][x];
            elems_set.insert(map[y][x]);
        }
    }

    std::vector<int> elems(elems_set.begin(), elems_set.end());

    int min_diff = 200;

    size_t l = 0;
    size_t r = 0;
    while (r < elems.size())
    {
        if (l <= r && exists_path(elems[l], elems[r]))
        {
            min_diff = std::min(min_diff, elems[r] - elems[l]);
            l++;
        }
        else
        {
            if (++r == elems.size())
                break;
        }
    }

    std::cout << min_diff;
}