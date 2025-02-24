#include <bits/stdc++.h>

int total_height, total_width;
int target_size;

struct Tile
{
    char color;
    int min_cost_horiz_w;
    int min_cost_horiz_b;
    int min_cost_verti_w;
    int min_cost_verti_b;
};

Tile board[2000][2000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> total_height >> total_width;
    std::cin >> target_size;

    for (int y = 0; y < total_height; y++)
    {
        for (int x = 0; x < total_width; x++)
            std::cin >> board[y][x].color;
    }

    for (int y = 0; y <= total_height - target_size; y++)
    {
        for (int x = 0; x <= total_width - target_size; x++)
        {
            
        }
    }
}