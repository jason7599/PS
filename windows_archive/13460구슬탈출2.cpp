#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int y;
    int x;
};

bool operator==(const pos& p0, const pos& p1)
{
    return p0.y == p1.y && p0.x == p1.x;
}

bool operator!=(const pos& p0, const pos& p1)
{
    return !(p0 == p1);
}

//  => r, d, l, u
const int dys[] = {0, 1, 0, -1};
const int dxs[] = {1, 0, -1, 0};

int board_height, board_width;
bool board_blocks[10][10];
pos exit_pos;

bool red_goes_first(pos red_pos, pos blu_pos, int direction)
{
    switch (direction)
    {
        case 0: // right
        return red_pos.x > blu_pos.x;

        case 1: // down
        return red_pos.y > blu_pos.y;

        case 2: // left
        return red_pos.x < blu_pos.x;

        case 3: // up
        return red_pos.y < blu_pos.y;
    }
    return -69;
}

pos calc_pos(pos ppos, int direction)
{
    int x = ppos.x;
    int y = ppos.y;
    while (board_blocks[y + dys[direction]][x + dxs[direction]] == false)
    {
        if (pos{y, x} == exit_pos)
            break;
        y += dys[direction];
        x += dxs[direction];
    }
    return {y, x};
}

pair<pos, pos> calc_moves(pos red_pos, pos blu_pos, int direction)
{
    pos new_red_pos, new_blu_pos;

    if (red_goes_first(red_pos, blu_pos, direction))
    {
        new_red_pos = calc_pos(red_pos, direction);
        
        if (new_red_pos != exit_pos)
            board_blocks[new_red_pos.y][new_red_pos.x] = true; // to block blu

        new_blu_pos = calc_pos(blu_pos, direction);

        board_blocks[new_red_pos.y][new_red_pos.x] = false;
    }
    else
    {
        new_blu_pos = calc_pos(blu_pos, direction);

        if (new_blu_pos != exit_pos)
            board_blocks[new_blu_pos.y][new_blu_pos.x] = true;

        new_red_pos = calc_pos(red_pos, direction);

        board_blocks[new_blu_pos.y][new_blu_pos.x] = false;
    }

    return {new_red_pos, new_blu_pos};
}

int solve(pos init_red_pos, pos init_blu_pos)
{
    queue<pair<pos, pos>> q;
    bool visited[10][10][10][10] = {false}; // [r.y][r.x][b.y][b.x]

    q.push({init_red_pos, init_blu_pos});
    visited[init_red_pos.y][init_red_pos.x][init_blu_pos.y][init_blu_pos.x] = true;

    int moves = 0;
    int q_size;

    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            pos red_pos = q.front().first;
            pos blu_pos = q.front().second;
            q.pop();

            if (red_pos == exit_pos)
                return moves;
            
            for (int d = 0; d < 4; d++)
            {
                pair<pos, pos> new_poss = calc_moves(red_pos, blu_pos, d);

                pos new_red_pos = new_poss.first;
                pos new_blu_pos = new_poss.second;

                if (new_blu_pos == exit_pos)
                    continue;
                
                if (!visited[new_red_pos.y][new_red_pos.x][new_blu_pos.y][new_blu_pos.x])
                {
                    visited[new_red_pos.y][new_red_pos.x][new_blu_pos.y][new_blu_pos.x] = true;
                    q.push(new_poss);
                }
            }
        }

        if (++moves > 10)
            break;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pos red_pos, blu_pos;

    cin >> board_height >> board_width;

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            char c; cin >> c;

            if (c == '#')
                board_blocks[y][x] = true;
            else if (c == 'R')
                red_pos = {y, x};
            else if (c == 'B')
                blu_pos = {y, x};
            else if (c == 'O')
                exit_pos = {y, x};
        }
    }

    cout << solve(red_pos, blu_pos);

    return 0;    
}