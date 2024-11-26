#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int board_height, board_width;
int board[1001][1001];

int safe_count;

bool oob(int y, int x)
{
    return y <= 0 || y > board_height || x <= 0 || x > board_width;
}

const int qdys[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int qdxs[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int kdys[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int kdxs[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void queen(int y, int x)
{
    for (int d = 0; d < 8; d++)
    {
        int ny = y;
        int nx = x;
        while (1)
        {
            ny += qdys[d];
            nx += qdxs[d];

            if (oob(ny, nx) || board[ny][nx] > 0)
                break;
            
            if (board[ny][nx] == 0)
            {
                board[ny][nx] = -1;
                safe_count--;
            }
        }
    }
}

void knight(int y, int x)
{
    for (int d = 0; d < 8; d++)
    {
        int ny = y + kdys[d];
        int nx = x + kdxs[d];

        if (oob(ny, nx) || board[ny][nx] > 0)
            continue;
        
        if (board[ny][nx] == 0)
        {
            board[ny][nx] = -1;
            safe_count--;
        }
    }
}

// void print_board()
// {
//     cout << '\n';
//     for (int y = 1; y <= board_height; y++)
//     {
//         for (int x = 1; x <= board_width; x++)
//         {
//             if (!board[y][x])
//                 cout << '.';
//             else if (board[y][x] == -1)
//                 cout << 'x';
//             else if (board[y][x] == 1)
//                 cout << 'Q';
//             else if (board[y][x] == 2)
//                 cout << 'K';
//             else if (board[y][x] == 3)
//                 cout << 'P';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> board_height >> board_width;

    safe_count = board_height * board_width;

    // q, k, p
    vector<pii> lads;
    for (int i = 1; i <= 3; i++)
    {
        int n;
        cin >> n;
        while (n--)
        {
            int y, x;
            cin >> y >> x;
            safe_count--;
            if ((board[y][x] = i) != 3)
                lads.push_back({y, x});
        }
    }

    for (auto lad : lads)
    {
        if (board[lad.first][lad.second] == 1)
            queen(lad.first, lad.second);
        else
            knight(lad.first, lad.second);
    }

    // print_board();

    cout << safe_count;
    return 0;
}