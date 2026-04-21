#include <bits/stdc++.h>

using namespace std;

const int MAX_BOARD_SIZE = 40;
const int MAX_STICKER_SIZE = 10;

class Sticker
{
private:
    int m_height, m_width;
    bool m_grid[MAX_STICKER_SIZE][MAX_STICKER_SIZE];
    int m_rot; // clockwise
    int m_count;
public:
    void init()
    {
        cin >> m_height >> m_width;
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                bool b;
                cin >> b;
                m_grid[y][x] = b;
                if (b)
                    m_count++;
            }
        }
    }

    void rotate() { m_rot = (m_rot + 1) % 4; }
    int get_count() const { return m_count; }

    pair<int, int> get_size() const
    {
        return m_rot % 2 ? make_pair(m_width, m_height) : make_pair(m_height, m_width);
    }

    bool get(int y, int x) const
    {
        switch (m_rot)
        {
        case 0: return m_grid[y][x];
        case 1: return m_grid[m_height - 1 - x][y];
        case 2: return m_grid[m_height - 1 - y][m_width - 1 - x];
        case 3: return m_grid[x][m_width - 1 - y];
        }
        assert(0);
    }
};

int board_height, board_width;
bool board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

bool can_place(const Sticker& sticker, int y, int x)
{
    const auto [height, width] = sticker.get_size();

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (sticker.get(i, j) && board[y + i][x + j])
                return 0;
        }
    }

    return 1;
}

void place(const Sticker& sticker, int y, int x)
{
    const auto [height, width] = sticker.get_size();

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (sticker.get(i, j))
                board[y + i][x + j] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> board_height >> board_width;

    int n_stickers;
    cin >> n_stickers;

    vector<Sticker> stickers(n_stickers);

    for (Sticker& sticker : stickers)
        sticker.init();

    int count_sum = 0;

    for (Sticker& sticker : stickers)
    {
        for (int rot = 0; rot < 4; rot++)
        {
            const auto [height, width] = sticker.get_size();
            
            for (int y = 0; y <= board_height - height; y++)
            {
                for (int x = 0; x <= board_width - width; x++)
                {
                    if (can_place(sticker, y, x))
                    {
                        place(sticker, y, x);
                        count_sum += sticker.get_count();
                        goto cont;
                    }
                }
            }
            sticker.rotate();
        }
        cont:
            continue;
    }

    cout << count_sum << '\n';
}
