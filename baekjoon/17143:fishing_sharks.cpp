#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using pii = std::pair<int, int>;

const int inf = 1e9;

// up down right left
const int dys[] = {0, -1, 1, 0, 0};
const int dxs[] = {0, 0, 0, 1, -1};

const int d_up = 1;
const int d_down = 2;
const int d_right = 3;
const int d_left = 4;

struct Shark
{
    int speed;
    int dir;
    int size;
};

int tank_height, tank_width;
std::map<pii, Shark> sharks;

int fisher_x;
int closest_shark_y;

bool is_oob(int y, int x)
{
    return y <= 0 || y > tank_height || x <= 0 || x > tank_width;
}

std::pair<pii, int> calc_next_pos_and_dir(pii pos, const Shark& shark)
{
    int ny = pos.first;
    int nx = pos.second;
    int ndir = shark.dir;

    if (dys[shark.dir]) // Moving vertically
    {
        int L = tank_height;
        int C = 2 * (L - 1); // Cycle length
        int distance = dys[shark.dir] * shark.speed;
        int total_distance = ny + distance - 1; // Adjust for 1-based indexing

        // Normalize total_distance to be within [0, C)
        int cycle_pos = ((total_distance % C) + C) % C;

        if (cycle_pos < L)
        {
            ny = cycle_pos + 1;
            ndir = (dys[shark.dir] > 0) ? d_down : d_up;
        }
        else
        {
            ny = 2 * L - cycle_pos - 1;
            ndir = (dys[shark.dir] > 0) ? d_up : d_down;
        }
    }
    else // Moving horizontally
    {
        int L = tank_width;
        int C = 2 * (L - 1); // Cycle length
        int distance = dxs[shark.dir] * shark.speed;
        int total_distance = nx + distance - 1; // Adjust for 1-based indexing

        // Normalize total_distance to be within [0, C)
        int cycle_pos = ((total_distance % C) + C) % C;

        if (cycle_pos < L)
        {
            nx = cycle_pos + 1;
            ndir = (dxs[shark.dir] > 0) ? d_right : d_left;
        }
        else
        {
            nx = 2 * L - cycle_pos - 1;
            ndir = (dxs[shark.dir] > 0) ? d_left : d_right;
        }
    }

    return {{ny, nx}, ndir};
}

void update_sharks()
{
    closest_shark_y = inf;

    std::map<pii, Shark> new_sharks;

    for (auto& [pos, shark] : sharks)
    {
        auto [new_pos, ndir] = calc_next_pos_and_dir(pos, shark);
        shark.dir = ndir;

        if (new_sharks.find(new_pos) == new_sharks.end()
            || new_sharks.at(new_pos).size < shark.size)
        {
            new_sharks[new_pos] = shark;
            if (new_pos.second == fisher_x + 1)
                closest_shark_y = std::min(closest_shark_y, new_pos.first);
        }
    }

    sharks = new_sharks;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_sharks;
    std::cin >> tank_height >> tank_width >> num_sharks;

    closest_shark_y = inf;
    fisher_x = 1;

    for (int i = 0; i < num_sharks; i++)
    {
        int y, x, speed, dir, size;
        std::cin >> y >> x >> speed >> dir >> size;
        sharks[{y, x}] = Shark{speed, dir, size};

        if (x == 1)
            closest_shark_y = std::min(closest_shark_y, y);
    }

    int score = 0;
    for (; fisher_x <= tank_width; fisher_x++)
    {
        if (closest_shark_y != inf)
        {
            std::cout << "got " << sharks[{closest_shark_y, fisher_x}].size;
            score += sharks[{closest_shark_y, fisher_x}].size;
            sharks.erase({closest_shark_y, fisher_x});
        }
        update_sharks();
    }
    std::cout << score;
}