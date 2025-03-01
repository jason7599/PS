#include <bits/stdc++.h>

using namespace std;

class Tetromino {
private:
    int m_height, m_width;
    vector<vector<bool>> m_grid;
    int m_rotate_variant;
    bool m_flip_variant;

    int m_rot = 0;
    bool m_flip = 0;

public:
    Tetromino(
        const vector<vector<bool>>& grid,
        int rotate_variant,
        bool flip_variant)
    : m_grid(grid), m_rotate_variant(rotate_variant), m_flip_variant(flip_variant),
      m_height(grid.size()), m_width(grid[0].size()) {}

    pair<int, int> get_size() {
        return m_rot % 2 ? make_pair(m_width, m_height) : make_pair(m_height, m_width);
    }

    int get_rotate_variant() { return m_rotate_variant; }
    int get_flip_variant() { return m_flip_variant; }
    void rotate() { m_rot = (m_rot + 1) % 4; }
    void flip() { m_flip = !m_flip; }

    bool get(int _y, int _x) const
    {
        int y, x;
        switch (m_rot)
        {
        case 0: y = _y, x = _x; break;
        case 1: y = m_height - 1 - _x, x = _y; break;
        case 2: y = m_height - 1 - _y, x = m_width - 1 - _x; break;
        case 3: y = _x, x = m_width - 1 - _y; break;
        }
        if (m_flip)
            x = m_width - 1 - x;
        return m_grid[y][x];
    }
};

vector<Tetromino> TETROMINOES = {
    Tetromino(
        {{1, 1, 1, 1}},
        1, 0
    ),
    Tetromino(
        {{1, 1},
         {1, 1}},
        0, 0
    ),
    Tetromino(
        {{1, 0},
         {1, 0},
         {1, 1}},
        3, 1
    ),
    Tetromino(
        {{1, 0},
         {1, 1},
         {0, 1}},
        3, 1
    ),
    Tetromino(
        {{1, 1, 1},
         {0, 1, 0}},
        3, 0
    )
};

int board_height, board_width;
int board[500][500];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> board_height >> board_width;

    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++)
            cin >> board[y][x];
    }

    int max_score = 0;
    
    for (Tetromino& tetromino : TETROMINOES) {

        for (int f = 0; f <= tetromino.get_flip_variant(); f++) {
            for (int r = 0; r <= tetromino.get_rotate_variant(); r++) {
                const auto [h, w] = tetromino.get_size();

                for (int y = 0; y <= board_height - h; y++) {
                    for (int x = 0; x <= board_width - w; x++) {
                        
                        int score = 0;
                        for (int i = 0; i < h; i++) {
                            for (int j = 0; j < w; j++) {
                                if (tetromino.get(i, j))
                                    score += board[y + i][x + j];
                            }
                        }
                        max_score = max(max_score, score);
                    }
                }
                tetromino.rotate();
            }
            tetromino.flip();
        }
    }

    cout << max_score << '\n';
}