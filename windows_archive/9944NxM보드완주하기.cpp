#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;

int board_height, board_width;
bool board_obstacles[30][30];
bool visited[30][30];

const int drow[] = {1, 0, -1, 0};
const int dcol[] = {0, 1, 0, -1};

int solve(int row, int col, int num_unvisited)
{
    if (num_unvisited == 0)
        return 0;

    int res = -1;

    for (int d = 0; d < 4; d++)
    {
        vector<pii> path;

        int nrow = row;
        int ncol = col;

        while (true)
        {
            nrow += drow[d];
            ncol += dcol[d];

            if (nrow < 0 || nrow >= board_height || ncol < 0 || ncol >= board_width
            || board_obstacles[nrow][ncol] || visited[nrow][ncol])
                break;
            
            visited[nrow][ncol] = true;
            num_unvisited--;
            path.push_back({nrow, ncol});
        }

        if (!path.empty())
        {
            int next = solve(nrow - drow[d], ncol - dcol[d], num_unvisited);
            if (next != -1)
            {
                if (res == -1 || next < res)
                    res = next;
            }

            for (pii p : path)
            {
                visited[p.first][p.second] = false;
                num_unvisited++;
            }
        }
    
    }

    return res == -1 ? -1 : res + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int case_num = 1;

    // ofstream fout;
    // fout.open("fuck.txt");

    while (!cin.eof())
    {
        cin >> board_height >> board_width;

        if (cin.eof())
            break;

        int num_unvisited = 0;
        for (int row = 0; row < board_height; row++)
        {
            for (int col = 0; col < board_width; col++)
            {
                char c; cin >> c;
                if (c == '.')
                {
                    board_obstacles[row][col] = false;
                    num_unvisited++;
                }
                else
                    board_obstacles[row][col] = true;
                
                visited[row][col] = false;
            }
        }

        int ans = -1;

        for (int row = 0; row < board_height; row++)
        {
            for (int col = 0; col < board_width; col++)
            {
                if (board_obstacles[row][col])
                    continue;

                visited[row][col] = true;
                int res = solve(row, col, num_unvisited - 1);
                if (res != -1)
                {
                    if (ans == -1 || res < ans)
                        ans = res;
                }
                visited[row][col] = false;
            }
        }


        cout << "Case " << case_num++ << ": " << ans << '\n';
        // fout << "Case " << case_num - 1 << ": " << ans << '\n';
    }

    // fout.close();
    

    return 0;
}