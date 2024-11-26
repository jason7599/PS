#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int board[9][9];
bool row_nums[9][10];
bool col_nums[9][10];
bool box_nums[3][3][10];

vector<pair<int, int>> unknowns;

void place_num(int y, int x, int n)
{
    board[y][x] = n;
    row_nums[y][n] = col_nums[x][n] = box_nums[y / 3][x / 3][n] = true;
}

bool check_present(int y, int x, int n)
{
    return row_nums[y][n] || col_nums[x][n] || box_nums[y / 3][x / 3][n];
}

void input_board()
{
    memset(row_nums, 0, sizeof(90));
    memset(col_nums, 0, sizeof(90));
    memset(box_nums, 0, sizeof(90));

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            char c;
            cin >> c;
            int n = c - '0';
            place_num(y, x, n);
            if (!n)
                unknowns.push_back({y, x});
        }
    }
}

int determine_num(int y, int x)
{
    int ans = 0;
    for (int n = 1; n <= 9; n++)
    {
        if (!check_present(y, x, n))
        {
            return n;
            // if (ans)
            //     return 0; // multiple candidates
            // ans = n;
        }
    }
    return ans;
}

void solve()
{
    for (auto it : unknowns)
    {
        int y = it.first;
        int x = it.second;

        int n;
        if ((n = determine_num(y, x)) != 0)
        {
            place_num(y, x, n);
        }
    }

    // while (!unknowns.empty())
    // {
    //     auto it = unknowns.begin();
    //     while (it != unknowns.end())
    //     {
    //         int y = it->first;
    //         int x = it->second;

    //         int n;
    //         if ((n = determine_num(y, x)) != 0)
    //         {
    //             place_num(y, x, n);
    //             it = unknowns.erase(it);
    //         }
    //         else
    //             ++it;
    //     }
    // }
}

void print_board()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
            cout << board[y][x];
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        input_board();

        solve();

        cout << "Scenario #" << i << ":\n";
        print_board();
        cout << '\n';
    }

    return 0;
}