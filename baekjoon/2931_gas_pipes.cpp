#include <iostream>
#include <queue>
#include <map>

// down, right, up, left
const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

const int d_down = 0;
const int d_right = 1;
const int d_up = 2;
const int d_left = 3;

struct Pipe
{
    bool in_dirs[4] = {0};
    std::vector<int> out_dirs;

    Pipe(std::vector<int> ins, std::vector<int> outs)
        : out_dirs(outs)
    {
        for (int i : ins)
            in_dirs[i] = 1;
    }
};

const std::map<char, Pipe> pipe_types = 
{
    {'|', Pipe({d_down, d_up}, {d_down, d_up})},
    {'-', Pipe({d_left, d_right}, {d_left, d_right})},
    {'+', Pipe({d_down, d_right, d_up, d_left}, {d_down, d_right, d_up, d_left})},
    {'1', Pipe({d_up, d_left}, {d_down, d_right})},
    {'2', Pipe({d_down, d_left}, {d_up, d_right})},
    {'3', Pipe({d_right, d_down}, {d_left, d_up})},
    {'4', Pipe({d_right, d_up}, {d_left, d_down})}
};

int map_height, map_width;
char map[25][25];
int num_pipes;
std::pair<int, int> point_a, point_b;

bool evaluate()
{
    static int visited[25][25];
    static int n_visited_id = 1;
    
    int visited_id = n_visited_id++;
    int num_pipes_reached = 0;
    bool point_b_reached = 0;

    std::queue<std::pair<int,int>> q;
    q.push(point_a);
    visited[point_a.first][point_a.second] = visited_id;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int dir : pipe_types.at(map[y][x]).out_dirs)
        {
            int ny = y + dys[dir];
            int nx = x + dxs[dir];

            if (ny < 0 || ny >= map_height || nx < 0 || nx >= map_width)
                continue;
            
            if (map[ny][nx] == '.')
                continue;

            if (!pipe_types.at(map[ny][nx]).in_dirs[dir])
                continue;
            
            if (visited[ny][nx] != visited_id)
            {
                visited[ny][nx] = visited_id;
                q.push({ny, nx});
                
                if (ny == point_b.first && nx == point_b.second)
                    point_b_reached = 1;
                else
                    num_pipes_reached++;
            }
        }
    }

    return point_b_reached && num_pipes_reached == num_pipes + 1;
}

int main()
{
    std::cin >> map_height >> map_width;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            char c;
            std::cin >> c;
            if (c == 'M')
            {
                point_a = {y, x};
                c = '+'; // hax
            }
            else if (c == 'Z')
            {
                point_b = {y, x};
                c = '+';
            }
            else if (c != '.')
                num_pipes++;

            map[y][x] = c;
        }
    }

    int ans_y, ans_x;
    char ans_ch;

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            if (map[y][x] != '.')
                continue;
            
            for (const auto& [ch, pipe] : pipe_types)
            {
                map[y][x] = ch;
                if (evaluate())
                {
                    ans_y = y + 1;
                    ans_x = x + 1;
                    ans_ch = ch;

                    goto end;
                }

                map[y][x] = '.';
            }
        }
    }

end:
    std::cout << ans_y << ' ' << ans_x << ' ' << ans_ch;
}