#include <iostream>

using namespace std;

int board_size;
char board[50][50];

int get_longest_streak(int y, int x, int dy, int dx)
{
    int longest_streak = 0;

    char prev = board[y][x];
    int streak = 1;

    int ny = y + dy;
    int nx = x + dx;
    while (ny < board_size && nx < board_size)
    {
        char cur = board[ny][nx];
        if (cur == prev)
            streak++;
        else
        {
            if (streak > longest_streak)
                longest_streak = streak;
            streak = 1;
            prev = cur;
        }

        ny += dy;
        nx += dx;
    }

    if (streak > longest_streak)
        longest_streak = streak;

    return longest_streak;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> board_size;
    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
            cin >> board[y][x];
    }

    // verti, hori
    const int dy[] = {1, 0};
    const int dx[] = {0, 1};

    int max_score = 0;

    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
        {
            char this_candy = board[y][x];
            for (int d = 0; d < 2; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= board_size|| nx < 0 || nx >= board_size)
                    continue;

                char swap_candy = board[ny][nx];
                if (this_candy == swap_candy)
                    continue;
                
                board[y][x] = swap_candy;
                board[ny][nx] = this_candy;

                int longest_streak = 0;
                for (int ty = 0; ty < board_size; ty++)
                {
                    int streak = get_longest_streak(ty, 0, 0, 1);
                    if (streak > longest_streak)
                        longest_streak = streak;
                }
                for (int tx = 0; tx < board_size; tx++)
                {
                    int streak = get_longest_streak(0, tx, 1, 0);
                    if (streak > longest_streak)
                        longest_streak = streak;
                }

                if (longest_streak > max_score)
                    max_score = longest_streak;

                // cout << "longest streak: " << longest_streak << '\n';
                // print_board();

                board[ny][nx] = swap_candy;
            }
            board[y][x] = this_candy;
        }
    }

    cout << max_score;
    return 0;
}