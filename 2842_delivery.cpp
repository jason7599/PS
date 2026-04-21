#include <iostream>
#include <queue>
#include <algorithm>

struct Pos
{
    int y;
    int x;
};

int map_size;
char map[50][50];
int alt_map[50][50];

const int dys[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dxs[] = {0, 1, 0, -1, 1, -1, 1, -1};

inline bool in_range(int x, int min, int max)
{
    return min <= x && x <= max;
}

bool solve(Pos start, int n_homes, int min_alt, int max_alt)
{
    static int visited[50][50];
    static int n_visit_id = 1;

    if (!in_range(alt_map[start.y][start.x], min_alt, max_alt))
        return 0;
    
    int visit_id = visited[start.y][start.x] = n_visit_id++;
    std::queue<Pos> q({start});

    while (!q.empty())
    {
        const auto [y, x] = q.front();
        q.pop();

        if (map[y][x] == 'K')
        {
            if (!--n_homes)
                return 1;
        }

        for (int d = 0; d < 8; d++)
        {
            int ny = y + dys[d];
            int nx = x + dxs[d];

            if (in_range(ny, 0, map_size - 1) 
            && in_range(nx, 0, map_size - 1)
            && visited[ny][nx] != visit_id
            && in_range(alt_map[ny][nx], min_alt, max_alt))
            {
                visited[ny][nx] = visit_id;
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

    std::cin >> map_size;
    Pos start;
    int n_homes = 0;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            char c;
            std::cin >> c;
            if (c == 'P')
                start = {y, x};
            else if (c == 'K')
                n_homes++;
            
            map[y][x] = c;
        }
    }

    std::vector<int> alts_asc;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            int alt;
            std::cin >> alt;
            alt_map[y][x] = alt;

            auto it = std::lower_bound(alts_asc.begin(), alts_asc.end(), alt);

            // no dups
            if (it != alts_asc.end() && *it == alt)
                continue;

            alts_asc.insert(it, alt);
        }
    }

    int min_fatigue = 1e9;

    size_t l = 0;
    size_t r = 0;
    while (l < alts_asc.size())
    {
        if (l <= r && solve(start, n_homes, alts_asc[l], alts_asc[r]))
        {
            min_fatigue = std::min(min_fatigue, alts_asc[r] - alts_asc[l]);
            l++;
        }
        else 
        {
            // todo; sus
            // intuition:
            // if we failed with max r, raising min_alt even higher won't do any wonders
            if (++r == alts_asc.size())
                break;
        }
    }

    std::cout << min_fatigue;
}