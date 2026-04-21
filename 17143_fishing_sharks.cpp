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

// <new_pos, is_asc>
std::pair<int, bool> ping_pong(int pos, int range)
{
    int cycle = 2 * (range - 1);
    int mod_pos = (pos - 1) % cycle;

    if (mod_pos < 0)
        mod_pos += cycle;
    
    if (mod_pos < range - 1)
        return {mod_pos + 1, 1};

    return {cycle - mod_pos + 1, 0};
}

std::pair<pii, int> calc_next_pos_and_dir(pii pos, const Shark& shark)
{
    if (dys[shark.dir]) // u || d
    {
        auto [ny, down] = ping_pong(pos.first + dys[shark.dir], tank_height);
        return {{ny, pos.second}, (down ? d_down : d_up)};
    }
    // r || l
    auto [nx, right] = ping_pong(pos.second + dxs[shark.dir], tank_width);
    return {{pos.first, nx}, (right ? d_right : d_left)};
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
            score += sharks[{closest_shark_y, fisher_x}].size;
            sharks.erase({closest_shark_y, fisher_x});
        }
        update_sharks();
    }
    std::cout << score;
}