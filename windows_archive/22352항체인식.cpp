#include <iostream>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int grid_height, grid_width;

void change(int grid[30][30], int row, int col, int val)
{
    bool visited[30][30] = {false};
    queue<pair<int,int>> q;

    int ogval = grid[row][col];

    visited[row][col] = true;
    grid[row][col] = val;
    q.push({row, col});

    const int drow[] = {1, 0, -1, 0};
    const int dcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nrow = crow + drow[d];
            int ncol = ccol + dcol[d];

            if (nrow < 0 || nrow >= grid_height || ncol < 0 || ncol >= grid_width
            || grid[nrow][ncol] != ogval || visited[nrow][ncol])
                continue;

            visited[nrow][ncol] = true;
            grid[nrow][ncol] = val;
            q.push({nrow, ncol});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int grid_before[30][30], grid_after[30][30];

    cin >> grid_height >> grid_width;

    FOR(row, grid_height)
    {
        FOR(col, grid_width)
            cin >> grid_before[row][col];
    }

    FOR(row, grid_height)
    {
        FOR(col, grid_width)
            cin >> grid_after[row][col];
    }

    FOR(row, grid_height)
    {
        FOR(col, grid_width)
        {
            if (grid_before[row][col] != grid_after[row][col])
            {
                change(grid_before, row, col, grid_after[row][col]);
                goto fuck;
            }
        }
    }

    cout << "YES";
    return 0;

fuck:
    FOR(row, grid_height)
    {
        FOR(col, grid_width)
        {
            if (grid_before[row][col] != grid_after[row][col])
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;
}