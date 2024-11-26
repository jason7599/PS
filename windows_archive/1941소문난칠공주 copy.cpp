#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int board_size = 5;
const int group_size = 7;

const char dasom = 'S';
const char doyun = 'Y';

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

char board[board_size][board_size];
bool selected[board_size][board_size];

int ans;

bool check(int start_y, int start_x)
{
    bool visited[board_size][board_size] = {false};
    queue<pii> q;

    visited[start_y][start_x] = true;
    q.push({start_y, start_x});

    int dasom_count = 0;
    int doyun_count = 0;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (board[y][x] == dasom)
            dasom_count++;
        else
            doyun_count++;
        
        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= board_size
            || nx < 0 || nx >= board_size
            || !selected[ny][nx]
            || visited[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    return (dasom_count + doyun_count == 7 && dasom_count >= 4);
}

void solve(int start_index = 0, int selected_count = 0)
{
    for (int index = start_index; index < board_size * board_size; index++)
    {
        int y = index / board_size;
        int x = index % board_size;

        selected[y][x] = true;
        if (++selected_count == group_size)
        {
            if (check(y, x))
                ans++;
        }
        else
            solve(index + 1, selected_count);

        selected_count--;
        selected[y][x] = false;
    }
}

int main()
{
    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
            cin >> board[y][x];
    }

    solve();

    cout << ans;

    return 0;
}