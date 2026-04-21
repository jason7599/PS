#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int m_h, m_w;
char grid[50][50];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m_h >> m_w;
    vector<pii> ps;
    for (int y = 0; y < m_h; y++) {
        for (int x = 0; x < m_w; x++) {
            cin >> grid[y][x];
            if (grid[y][x] == '0') {
                if (0 < y && y < m_h - 1 && 0 < x && x < m_w - 1) {
                    ps.push_back({y, x});
                }
            }
        }
    }

    pii pos;
    int n_loc = 0;
    for (const auto& [y, x] : ps) {
        for (int ny = y - 1; ny <= y + 1; ny++) {
            for (int nx = x - 1; nx <= x + 1; nx++) {
                if (ny == y && nx == x) {
                    continue;
                }
                if (grid[ny][nx] != 'O') {
                    goto cont;
                }
            }
        }
        pos = {y, x};
        n_loc++;
cont:
        continue;
    }

    if (n_loc == 1) {
        cout << pos.first + 1 << ' ' << pos.second + 1 << '\n';
    } else {
        cout << "Oh no!";
        if (n_loc) {
            cout << ' ' << n_loc << " locations";
        }
        cout << '\n';
    }
}
