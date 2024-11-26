#include <iostream>
#include <queue>
#include <set>

using namespace std;

int num_pieces;

bool get_piece(int board, int pos)
{
    return (board >> pos) & 1;
}

int set_piece(int board, int pos, int val)
{
    if (val)
        board |= (1 << pos);
    else
        board &= ~(1 << pos);
    return board;
}

/**
 * @return int: bit index, -1 if oob
 */
int get_pos(int pos, int dir)
{
    switch (dir)
    {
        case 0: // right
        if ((pos + 1) % 5 == 0)
            return -1;
        return pos + 1;

        case 1: // down
        if (pos >= 20)
            return -1;
        return pos + 5;

        case 2: // left
        if (pos % 5 == 0)
            return -1;
        return pos - 1;
    
        case 3: // up
        if (pos < 5)
            return -1;
        return pos - 5;
    }
    return -1;
}

bool is_board_solved(int board)
{
    int init_pos;
    for (init_pos = 0; init_pos < 25; init_pos++)
    {
        if (get_piece(board, init_pos))
            break;
    }

    bool visited[25] = {false};
    visited[init_pos] = true;

    queue<int> q;
    q.push(init_pos);

    int size = 0;

    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        
        if (++size == num_pieces)
            return true;

        for (int d = 0; d < 4; d++)
        {
            int n_pos = get_pos(pos, d);
            if (n_pos == -1 || !get_piece(board, n_pos) || visited[n_pos])
                continue;
            
            visited[n_pos] = true;
            q.push(n_pos);
        }
    }

    return false;
}

int solve(int init_board)
{
    set<int> visited;
    queue<int> q;

    visited.insert(init_board);
    q.push(init_board);

    int moves = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            int board = q.front();
            q.pop();

            if (is_board_solved(board))
                return moves;
            
            int i = 0;
            int pos = 0;

            while (i < num_pieces)
            {
                while (!get_piece(board, pos))
                    pos++;

                for (int d = 0; d < 4; d++)
                {
                    int n_pos = get_pos(pos, d);
                    if (n_pos == -1 || get_piece(board, n_pos))
                        continue;
                    
                    int n_board = set_piece(set_piece(board, pos, 0), n_pos, 1);

                    if (visited.find(n_board) == visited.end())
                    {
                        visited.insert(n_board);
                        q.push(n_board);
                    }
                }

                i++;
                pos++;
            }
        }

        moves++;
    }

    return -1;
}

int main()
{
    int init_board = 0;
    
    for (int i = 0; i < 25; i++)
    {
        char c;
        cin >> c;
        if (c == '*')
        {
            init_board = set_piece(init_board, i, 1);
            num_pieces++;
        }
    }

    cout << solve(init_board);

    return 0;
}