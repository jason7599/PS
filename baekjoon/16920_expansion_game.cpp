#include <iostream>
#include <queue>

using pii = std::pair<int,int>;

struct player
{
    char ch;
    int expand_dist;
    std::queue<pii> expand_q;
};

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

char board[1000][1000];

int main()
{
    int board_height, board_width;

    int num_players;
    player players[9];

    std::cin >> board_height >> board_width >> num_players;
    for (int i = 0; i < num_players; i++)
    {
        players[i].ch = i + '1';
        std::cin >> players[i].expand_dist; 
    }

    int coverage[9] = {0};

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            char c;
            std::cin >> c;
            board[y][x] = c;

            if ('1' <= c && c <= '9')
            {
                players[c - '1'].expand_q.push({y, x});
                coverage[c - '1']++;
            }
        }
    }

    while (1)
    {
        bool game_over = 1;
        for (int p = 0; p < num_players; p++)
        {
            player& player = players[p];

            int dist = player.expand_dist;
            int q_size;

            while (dist-- && (q_size = player.expand_q.size()))
            {
                while (q_size--)
                {
                    int y = player.expand_q.front().first;
                    int x = player.expand_q.front().second;
                    player.expand_q.pop();

                    for (int d = 0; d < 4; d++)
                    {
                        int ny = y + dys[d];
                        int nx = x + dxs[d];

                        if (ny < 0 || ny >= board_height || nx < 0 || nx >= board_width)
                            continue;
                        
                        if (board[ny][nx] == '.')
                        {
                            game_over = 0;

                            board[ny][nx] = player.ch;
                            player.expand_q.push({ny, nx});
                            coverage[p]++;
                        }
                    }
                }
            }
        }
        
        if (game_over)
            break;
    }

    for (int p = 0; p < num_players; p++)
        std::cout << coverage[p] << ' ';
}