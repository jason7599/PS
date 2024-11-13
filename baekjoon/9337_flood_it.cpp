#include <iostream>
#include <queue>
#include <algorithm>

using pii = std::pair<int, int>; 

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int board_size;
int board[20][20];

std::vector<pii> get_tiles(int color)
{

}

int main()
{
    int num_tc;
    std::cin >> num_tc;

    while (num_tc--)
    {
        std::cin >> board_size;

        int num_colors[6] = {0};
        bool done = 0;
        
        for (int y = 0; y < board_size; y++)
        {
            for (int x = 0; x < board_size; x++)
            {
                char c;
                std::cin >> c;
                board[y][x] = c - '1';
                if (++num_colors[c - '1'] == board_size * board_size)
                    done = 1;
            }
        }

        int moves = 0;
        int num_chosen[6] = {0};

        while (!done)
        {
            
        }

        std::cout << moves << '\n';
        for (int i = 0; i < 6; i++)
            std::cout << num_chosen[i] << ' ';
        std::cout << '\n';
    }
}