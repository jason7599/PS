#include <iostream>
#include <queue>
#include <string>

struct Pos
{
    int y;
    int x;
};

const std::string dirs = "URDL";
const int dys[] = {-1, 0, 1, 0};
const int dxs[] = {0, 1, 0, -1};

int map_height, map_width;

Pos turtle_pivot{-1};
std::vector<Pos> turtle_shape;
int turtle_max_y_offset;
int turtle_min_x_offset;
int turtle_max_x_offset;

Pos dest_pos;
std::vector<Pos> obstacles;

bool obstruction_zone[1000][1000]; // if 1, turtle cannot be placed
bool win_zone[1000][1000];

inline bool is_oob(int y, int x)
{
    return y < 0 || y >= map_height || x < 0 || x >= map_width;
}

void map_obstruction_zone()
{
    for (const auto& [obs_y, obs_x] : obstacles)
    {
        for (const auto& [off_y, off_x] : turtle_shape)
        {
            int t_y = obs_y - off_y;
            int t_x = obs_x - off_x;

            if (!is_oob(t_y, t_x))
                obstruction_zone[t_y][t_x] = 1;
        }
    }
}

void map_win_zone()
{
    for (const auto& [off_y, off_x] : turtle_shape)
    {
        int t_y = dest_pos.y - off_y;
        int t_x = dest_pos.x - off_x;

        if (!is_oob(t_y, t_x))
            win_zone[t_y][t_x] = 1;
    }
}

struct QEntry
{
    Pos pos;
    std::string path;
};

bool can_move_turtle_to(int y, int x)
{
    if (is_oob(y + turtle_max_y_offset, x + turtle_min_x_offset))
        return 0;

    if (is_oob(y + turtle_max_y_offset, x + turtle_max_x_offset))
        return 0;

    if (obstruction_zone[y][x])
        return 0;

    return 1;
}

std::string solve()
{
    static bool visited[1000][1000];
    std::queue<QEntry> q({{turtle_pivot, ""}});
    visited[turtle_pivot.y][turtle_pivot.x] = 1;

    while (!q.empty())
    {
        const auto& [pos, path] = q.front();
        q.pop();

        if (win_zone[pos.y][pos.x])
            return path;
        
        for (int d = 0; d < 4; d++)
        {
            int ny = pos.y + dys[d];
            int nx = pos.x + dxs[d];

            if (!is_oob(ny, nx)
            && !visited[ny][nx]
            && can_move_turtle_to(ny, nx))
            {
                visited[ny][nx] = 1;
                q.push({{ny, nx}, path + dirs[d]});
            }
        }
    }

    return "-1";
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> map_height >> map_width;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            std::cin >> c;

            if (c == 'T')
            {
                if (turtle_pivot.y == -1)
                {
                    turtle_pivot = {y, x};
                    turtle_shape.push_back({0, 0});
                }
                else
                {
                    int y_offset = y - turtle_pivot.y;
                    int x_offset = x - turtle_pivot.x;

                    turtle_max_y_offset = std::max(turtle_max_y_offset, y_offset);
                    turtle_min_x_offset = std::min(turtle_min_x_offset, x_offset);
                    turtle_max_x_offset = std::max(turtle_max_x_offset, x_offset);

                    turtle_shape.push_back({y_offset, x_offset});
                }
            }
            else if (c == 'H')
                dest_pos = {y, x};
            else if (c == '#')
                obstacles.push_back({y, x});
        }
    }

    map_obstruction_zone();
    map_win_zone();

    std::cout << solve();
}