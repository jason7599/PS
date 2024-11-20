#include <iostream>
#include <vector>
#include <map>

constexpr int DYS[] = {1, 0, -1, 0};
constexpr int DXS[] = {0, 1, 0, -1};

constexpr int D_DOWN = 0;
constexpr int D_RIGHT = 1;
constexpr int D_UP = 2;
constexpr int D_LEFT = 3;

struct Pipe
{
    const std::vector<int> out_dirs;
    int in_dir_m = 0;

    Pipe(const std::vector<int>& out,
        const std::vector<int>& in)
        : out_dirs(out)
    {
        for (int i : in)
            in_dir_m |= 1 << i;
    }
};

const std::map<char, Pipe> pipes = 
{
//    c             out                 in
    {'|', Pipe(     {D_UP, D_DOWN},     {D_UP, D_DOWN})},
    {'-', Pipe(     {D_LEFT, D_RIGHT},  {D_LEFT, D_RIGHT})},
    {'+', Pipe(     {D_LEFT, D_UP, D_RIGHT, D_DOWN}, {D_LEFT, D_UP, D_RIGHT, D_DOWN})},
    {'1', Pipe(     {D_DOWN, D_RIGHT},  {D_LEFT, D_UP})},
    {'2', Pipe(     {D_RIGHT, D_UP},    {D_LEFT, D_DOWN})},
    {'3', Pipe(     {D_LEFT, D_UP},     {D_RIGHT, D_DOWN})},
    {'4', Pipe(     {D_LEFT, D_DOWN},   {D_RIGHT, D_UP})}
};

int map_height, map_width;
char map[25][25];

int main()
{
    std::cin >> map_height >> map_width;
    std::vector<std::pair<int, int>> pipe_locs;
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            std::cin >> map[y][x];
            if (map[y][x] != 'M'
            && map[y][x] != 'Z'
            && map[y][x] != '.')
                pipe_locs.push_back({y, x});
        }
    }

    std::pair<int, int> req_loc;
    int req_in_dir_m = 0;

    for (const auto& [y, x] : pipe_locs)
    {
        const Pipe& pipe = pipes.at(map[y][x]);

        for (int d : pipe.out_dirs)
        {
            int ny = y + DYS[d];
            int nx = x + DXS[d];

            // no oob check 

            if (map[ny][nx] == '.')
            {
                req_loc = {ny, nx};
                req_in_dir_m |= 1 << d;
            }
        }
    }

    std::cout << req_loc.first + 1 << ' ' << req_loc.second + 1;
    for (const auto& [c, pipe] : pipes)
    {
        if (pipe.in_dir_m == req_in_dir_m)
        {
            std::cout << ' ' << c;
            break;
        }
    }
}