#include <iostream>
#include <vector>
#include <map>

const int DYS[] = {0, -1, 1, 0, 0};
const int DXS[] = {0, 0, 0, -1, 1};

struct Pos
{
    int y, x;
};

struct Shark
{
    int id;
    int dir;
    int dir_priorities[5][4] = {0};
};

struct Odor
{
    int shark;
    int t_created;
};

int map_size;
Odor odor_map[20][20];

int main()
{
    int n_sharks, odor_ttl;
    std::cin >> map_size >> n_sharks >> odor_ttl;

    std::vector<std::pair<Pos, Shark>> shark_list(n_sharks);

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            int t;
            std::cin >> t;
            if (t)
                shark_list[t - 1] = {{y, x}, Shark{t}};
        }
    }

    for (int i = 0; i < n_sharks; i++)
        std::cin >> shark_list[i].second.dir;

    for (int i = 0; i < n_sharks; i++)
    {
        for (int d = 1; d <= 4; d++)
        {
            for (int j = 0; j < 4; j++)
                std::cin >> shark_list[i].second.dir_priorities[d][j];
        }
    }

    std::map<Pos, Shark> sharks;
}