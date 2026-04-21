#include <iostream>
#include <vector>

char board[9][9];
bool row_nums[9][10];
bool col_nums[9][10];
bool box_nums[3][3][10];

bool can_place(int y, int x, int n)
{
    return !row_nums[y][n]
        && !col_nums[x][n]
        && !box_nums[y / 3][x / 3][n];
}

void place(int y, int x, int n)
{
    board[y][x] = n + '0';

    row_nums[y][n]
    = col_nums[x][n]
    = box_nums[y / 3][x / 3][n]
    = 1; 
}

int main()
{
    bool error = 0;
    std::vector<std::pair<int,int>> emptyshit;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            char c;
            std::cin >> c;

            if (c != '.' && !error)
            {
                if (!can_place(y, x, c - '0'))
                    error = 1;
                else
                    place(y, x, c - '0');
            }
            else
            {
                emptyshit.push_back({y, x});
                board[y][x] = '.';
            }
        }
    }

    if (error)
    {
        std::cout << "ERROR";
        return 0;
    }

    // ugliest shit i've ever seen but idc
    while (1)
    {
        bool done = 1;
        for (int by = 0; by < 3; by++)
        {
            for (int bx = 0; bx < 3; bx++)
            {
                for (int n = 1; n <= 9; n++)
                {
                    if (box_nums[by][bx][n])
                    stop:
                        continue;
                    
                    int ans_y = -1;
                    int ans_x = -1;
                    for (int y = by * 3; y < (by + 1) * 3; y++)
                    {
                        for (int x = bx * 3; x < (bx + 1) * 3; x++)
                        {
                            if (board[y][x] == '.' && can_place(y, x, n))
                            {
                                if (ans_y != -1)
                                    goto stop;
                                
                                ans_y = y;
                                ans_x = x;
                            }
                        }
                    }

                    place(ans_y, ans_x, n);
                    done = 0;
                    break;
                }
            }
        }

        if (done)
            break;
    }

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            std::cout << board[y][x];
        }
        std::cout << '\n';
    }
}