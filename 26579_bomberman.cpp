#include <iostream>
#include <vector>

using namespace std;

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int get_score(const vector<vector<char>>& map, int y, int x)
{
    int score = 0;

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dys[d];
        int nx = x + dxs[d];

        while (0 <= ny && ny < map.size() && 0 <= nx && nx < map[0].size()
            && map[ny][nx] != '#')
        {
            if (map[ny][nx] == '@')
                score++;
            
            ny += dys[d];
            nx += dxs[d];
        }
    }

    return score;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int height, width;
        cin >> height >> width;

        vector<vector<char>> map (height);

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                char c;
                cin >> c;
                map[y].push_back(c);
            }
        }

        int best_score = 0;
        int best_y, best_x;
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (map[y][x] == '.')
                {
                    int score = get_score(map, y, x);
                    if (score > best_score)
                    {
                        best_score = score;
                        best_y = y;
                        best_x = x;
                    }
                }
            }
        }

        cout << best_y << ", " << best_x << '\n';
    }

    return 0;
}