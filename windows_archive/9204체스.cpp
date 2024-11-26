#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int rtoi(int r){ return 8 - r; }
int ctoi(char c) { return c - 'A'; }
int itor(int i) { return 8 - i; }
char itoc(int i) { return 'A' + i; }

vector<pii> solve(int sy, int sx, int ty, int tx)
{
    bool v[9][9] = {0};
    queue<pair<pii, vector<pii>>> q;

    v[sy][sx] = 1;
    q.push({{sy, sx}, {}});

    int t = 0;
    int qs;
    while ((qs = q.size()) != 0)
    {
        while (qs--)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            vector<pii> p = q.front().second;
            q.pop();

            p.push_back({y, x});

            if (y == ty && x == tx)
                return p;

            for (int dy = -1; dy <= 1; dy += 2)
            {
                for (int dx = -1; dx <= 1; dx += 2)
                {
                    int ny = y + dy;
                    int nx = x + dx;

                    while (0 <= ny && ny < 9 && 0 <= nx && nx < 9)
                    {
                        if (!v[ny][nx])
                        {
                            v[ny][nx] = 1;
                            q.push({{ny, nx}, p});
                        }

                        ny += dy;
                        nx += dx;
                    }
                }
            }
        }

        if (++t > 4)
            break;
    }

    return {};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        char c0, c1;
        int i0, i1;
        cin >> c0 >> i0 >> c1 >> i1;

        vector<pii> res = solve(rtoi(i0), ctoi(c0), rtoi(i1), ctoi(c1));
        if (res.empty())
            cout << "Impossible";
        else
        {
            cout << res.size() - 1;
            for (pii pos : res)
                cout << ' ' << itoc(pos.second) << ' ' << itor(pos.first);
        }
        cout << '\n';
    }

    return 0;
}