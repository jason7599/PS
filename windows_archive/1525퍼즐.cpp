#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

const string ans = "123456780";

void print_board(const string& board)
{
    cout << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << board[i * 3 + j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

string swap_empty(const string& board, int zero_idx, int swap_idx)
{
    string swapped = board;
    char temp = swapped[zero_idx];
    swapped[zero_idx] = swapped[swap_idx];
    swapped[swap_idx] = temp;
    return swapped;
}

bool fuck(const string& board, int zero_idx, int swap_idx, set<string>& visited, queue<pair<string, int>>& q)
{
    string next_board = swap_empty(board, zero_idx, swap_idx);
    if (next_board == ans)
        return true;
    if (visited.find(next_board) == visited.end())
    {
        visited.insert(next_board);
        q.push({next_board, swap_idx});
    }
    return false;
}

int solve(const string& init_board, int init_zero_idx)
{
    if (init_board == ans)
        return 0;

    set<string> visited;
    queue<pair<string, int>> q;

    visited.insert(init_board);
    q.push({init_board, init_zero_idx});

    int moves = 1;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            string board = q.front().first;
            int zero_idx = q.front().second;
            q.pop();

            // print_board(board);

            if (zero_idx % 3) // can swap left
            {
                if (fuck(board, zero_idx, zero_idx - 1, visited, q))
                    return moves;
            }
            if ((zero_idx + 1) % 3) // can swap right
            {
                if (fuck(board, zero_idx, zero_idx + 1, visited, q))
                    return moves;
            }
            if (zero_idx - 3 >= 0) // swap up
            {
                if (fuck(board, zero_idx, zero_idx - 3, visited, q))
                    return moves;
            }
            if (zero_idx + 3 <= 8) // down
            {
                if (fuck(board, zero_idx , zero_idx + 3, visited, q))
                    return moves;
            }
        }

        moves++;
    }

    return -1;
}

int main()
{
    string board;
    int zero_idx;

    for (int i = 0; i < 9; i++)
    {
        char c; cin >> c;
        if (c == '0')
            zero_idx = i;
        board += c;
    }

    cout << solve(board, zero_idx);
}