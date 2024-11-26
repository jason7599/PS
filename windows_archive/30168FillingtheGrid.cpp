#include <iostream>

using namespace std;

const short t_nset = 0;
const short t_none = 1;
const short t_full = 2;

const int mod = 1e9 + 7;

int numRows, numCols;
short grid[1000][1000];

// void print_grid()
// {
//     cout << "=== GRID ===\n";

//     for (int row = 0; row < numRows; row++)
//     {
//         for (int col = 0; col < numCols; col++)
//         {
//             if (grid[row][col] == t_nset)
//                 cout << '?';
//             else if (grid[row][col] == t_none)
//                 cout << '0';
//             else
//                 cout << '1';
            
//             cout << ' ';
//         }
//         cout <<'\n';
//     }
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> numRows >> numCols;

    int nset_cnt = numRows * numCols;

    for (int row = 0; row < numRows; row++)
    {
        int x;
        cin >> x;
        for (int col = 0; col < x; col++)
        {
            grid[row][col] = t_full;
            nset_cnt--;
        }
        if (x != numCols)
        {
            grid[row][x] = t_none;
            nset_cnt--;
        }
    }

    for (int col = 0; col < numCols; col++)
    {
        bool bad = 0;

        int x;
        cin >> x;
        for (int row = 0; row < x; row++)
        {
            if (grid[row][col] == t_none)
            {
                bad = true;
                break;
            }
            if (grid[row][col] != t_full)
            {
                grid[row][col] = t_full;
                nset_cnt--;
            }
        }
        if (x != numRows)
        {
            if (grid[x][col] == t_full)
                bad = true;
            else if (grid[x][col] != t_none)
            {
                grid[x][col] = t_none;
                nset_cnt--;
            }
        }

        if (bad)
        {
            cout << 0;
            return 0;
        }
    }

    // print_grid();

    // cout << nset_cnt;

    int ans = 1;
    for (int i = 0; i < nset_cnt; i++)
        ans = (ans * 2) % mod; 

    cout << ans;

    return 0;
}