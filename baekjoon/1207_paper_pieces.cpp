#include <bits/stdc++.h>

using Board = std::vector<std::vector<int>>;

struct Piece
{
    int id;
    std::vector<std::vector<bool>> tiles;
};

bool try_place(const Piece& piece, int board_size, Board& board, int y, int x)
{
    int h = piece.tiles.size();
    int w = piece.tiles[0].size();

    if (y + h - 1 >= board_size
    || x + w - 1 >= board_size)
        return 0;
    
    int i = 0;
    int j = 0;

    for (; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (!piece.tiles[i][j])
                continue;

            int& t = board[y + i][x + j];
            if (t)
                goto rollback;
            t = piece.id;
        }
    }

    return 1;

rollback:
    j--;
    while (i >= 0)
    {
        while (j >= 0)
        {
            if (piece.tiles[i][j])
                board[y + i][x + j] = 0;
            j--;
        }
        i--;
        j = w - 1;
    }
    return 0;
}

void undo(const Piece& piece, Board& board, int y, int x)
{
    for (int i = 0; i < piece.tiles.size(); i++)
    {
        for (int j = 0; j < piece.tiles[0].size(); j++)
        {
            if (piece.tiles[i][j])
                board[y + i][x + j] = 0;
        }
    }
}

bool _solve(
    const std::array<Piece, 5>& pieces,
    int board_size,
    Board& board,
    int used_mask,
    int pos_idx
)
{
    if (used_mask == (1 << 5) - 1)
        return 1;

    if (pos_idx == board_size * board_size)
        return 0;
    
    int y = pos_idx / board_size;
    int x = pos_idx % board_size;

    if (board[y][x])
        return _solve(pieces, board_size, board, used_mask, pos_idx + 1);
    
    for (int p = 0; p < 5; p++)
    {
        if (used_mask & (1 << p))
            continue;
        
        if (try_place(pieces[p], board_size, board, y, x))
        {
            if (_solve(pieces, board_size, board, used_mask | (1 << p), pos_idx + 1))
                return 1;
            
            undo(pieces[p], board, y, x);
        }
    }

    return 0;
}

Board solve(int board_size, const std::array<Piece, 5>& pieces)
{
    Board board;
    board.resize(board_size, std::vector<int> (board_size));

    if (_solve(pieces, board_size, board, 0, 0))
        return board;
    
    return {};
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int board_size;
    std::cin >> board_size;

    std::array<Piece, 5> pieces;

    for (int i = 0; i < 5; i++)
    {
        Piece piece;
        piece.id = i + 1;

        int h, w;
        std::cin >> h >> w;

        piece.tiles.resize(h, std::vector<bool>(w));

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                char c;
                std::cin >> c;
                piece.tiles[y][x] = c == '#';
            }
        }

        pieces[i] = piece;
    }

    Board res = solve(board_size, pieces);

    if (res.empty())
        std::cout << "gg\n";
    else
    {
        for (auto r : res)
        {
            for (int c : r)
                std::cout << c;
            std::cout << '\n';
        }
    }
}