#include <iostream>

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

struct Pos
{
    int y;
    int x;

    bool operator==(const Pos& other) const
    {
        return y == other.y && x == other.x;
    }
};

int b_height, b_width;
int dir_memo[9][9];

bool solve(Pos pos, Pos dest, int idx = 0)
{
    if (++idx == b_height * b_width)
        return pos == dest;
    
    if (pos == dest)
        return 0;

    for (int d = 0; d < 4; d++)
    {
        int ny = pos.y + dys[d];
        int nx = pos.x + dxs[d];

        if (ny <= 0 || ny > b_height || nx <= 0 || nx > b_width)
            continue;
        
        if (dir_memo[ny][nx] == -1)
        {
            dir_memo[pos.y][pos.x] = d;

            if (solve({ny, nx}, dest, idx))
                return 1;
        }
    }

    dir_memo[pos.y][pos.x] = -1;
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::cin >> b_height >> b_width;

        for (int y = 1; y <= b_height; y++)
        {
            for (int x = 1; x <= b_width; x++)
                dir_memo[y][x] = -1;
        }

        Pos start, dest;
        std::cin >> start.y >> start.x;
        std::cin >> dest.y >> dest.x;

        if (solve(start, dest))
        {
            std::cout << 1 << '\n';
            
            auto [y, x] = start;
            while (y != dest.y || x != dest.x)
            {
                std::cout << y << ' ' << x << '\n';
                int d = dir_memo[y][x];
                y += dys[d];
                x += dxs[d];
            }
            std::cout << y << ' ' << x << '\n';
        }
        else
            std::cout << -1 << '\n';
    }
}