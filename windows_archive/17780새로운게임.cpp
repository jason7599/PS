#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int,int>;

const int tile_white = 0;
const int tile_red = 1;
const int tile_blue = 2;

const int dys[] = {0, 0, 0, -1, 1};
const int dxs[] = {0, 1, -1, 0, 0};

int board_size, num_pieces;
int board_tiles[13][13];

vector<int> board_pieces[13][13];
pii piece_pos[10];
int piece_dir[10];

bool win_condition;

int reverse_dir(int dir)
{
    switch (dir)
    {
        case 1: return 2;
        case 2: return 1;
        case 3: return 4;
        case 4: return 3;
    }
    return -1;
}

bool is_oob(int y, int x)
{
    return y <= 0 || y > board_size || x <= 0 || x > board_size;
}

void move_pieces(int y, int x, int ny, int nx)
{
    vector<int> pieces = board_pieces[y][x];
    board_pieces[y][x].clear();

    if (board_tiles[ny][nx] == tile_white)
    {
        for (int piece : pieces)
        {
            board_pieces[ny][nx].push_back(piece);
            piece_pos[piece] = {ny, nx};
        }
    }
    else // red
    {
        for (int i = pieces.size() - 1; i >= 0; i--)
        {
            int piece = pieces[i];
            board_pieces[ny][nx].push_back(piece);
            piece_pos[piece] = {ny, nx};
        }
    }

    if (board_pieces[ny][nx].size() >= 4)
        win_condition = true;
}

int main()
{
    cin >> board_size >> num_pieces;

    for (int y = 1; y <= board_size; y++)
    {
        for (int x = 1; x <= board_size; x++)
        {
            cin >> board_tiles[y][x];
        }
    }

    for (int i = 0; i < num_pieces; i++)
    {
        int y, x, d;
        cin >> y >> x >> d;
        piece_pos[i] = {y, x};
        piece_dir[i] = d;

        board_pieces[y][x].push_back(i);
    }

    int turn = 0;
    while (turn++ <= 1000)
    {
        for (int piece = 0; piece < num_pieces; piece++)
        {
            int y = piece_pos[piece].first;
            int x = piece_pos[piece].second;

            if (board_pieces[y][x].front() != piece)
                continue;
            
            int ny = y + dys[piece_dir[piece]];
            int nx = x + dxs[piece_dir[piece]];

            if (is_oob(ny, nx) || board_tiles[ny][nx] == tile_blue)
            {
                piece_dir[piece] = reverse_dir(piece_dir[piece]);

                ny = y + dys[piece_dir[piece]];
                nx = x + dxs[piece_dir[piece]];

                if (!is_oob(ny, nx) && board_tiles[ny][nx] != tile_blue)
                {
                    move_pieces(y, x, ny, nx);
                }
            }
            else
                move_pieces(y, x, ny, nx);
            
            if (win_condition)
            {
                cout << turn;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}