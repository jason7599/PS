#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

// r, d, l, u
const int dys[] = {0, 1, 0, -1};
const int dxs[] = {1, 0, -1, 0}; 

int map_radius;

int get_move_dist(int y, int x, int dir, int dist)
{
    
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_turns;
    std::cin >> map_radius >> num_turns;

    int snake_y = 0, snake_x = 0, snake_dir = 0;
    int time = 0;
    while (num_turns--)
    {
        int dist;
        char dir;
        std::cin >> dist >> dir;

        int move_dist = get_move_dist(snake_y, snake_x, snake_dir, dist); 
        
        time += move_dist;

        if (move_dist != dist)
            break;

        snake_y += dys[snake_dir] * dist;
        snake_x += dxs[snake_dir] * dist;
        snake_dir = dir;
    }


}
