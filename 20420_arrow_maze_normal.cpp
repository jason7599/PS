#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// D, R, U, L
const pii MOVES[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int m_h, m_w, maze[50][50];
bool vis[50][50][151][151];

void f(int k) {
    vis[0][0][k][k] = 1;
    queue<pair<pii, pii>> q({{{0, 0}, {k, k}}});

    auto push = [&](int y, int x, int d, int l, int r) {
        y += MOVES[d].first;
        x += MOVES[d].second;

        if (y < 0 || y >= m_h || x < 0 || x >= m_w) {
            return;
        }
        if (y == m_h - 1 && x == m_w - 1) {
            cout << "Yes\n";
            exit(0);
        }
        if (!vis[y][x][l][r]) {
            vis[y][x][l][r] = 1;
            q.push({{y, x}, {l, r}});
        }
    };

    while (q.size()) {
        const auto [y, x] = q.front().first;
        const auto [l, r] = q.front().second;
        q.pop();

        push(y, x, maze[y][x], l, r);

        for (int i = 1; i <= min(l, 2 + (r == 0)); i++) {
            push(y, x, (maze[y][x] + i) % 4, l - i, r);
        }
        for (int i = 1; i <= min(r, 2 + (l == 0)); i++) {
            push(y, x, (maze[y][x] + 4 - i) % 4, l, r - i);
        }
    }

    cout << "No\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int k;
    cin >> m_h >> m_w >> k;
    for (int y = 0; y < m_h; y++) {
        for (int x = 0; x < m_w; x++) {
            char c;
            cin >> c;
            switch (c) {
            case 'L': maze[y][x]++; 
            case 'U': maze[y][x]++;
            case 'R': maze[y][x]++;
            }
        }
    }

    if (m_h == 1 && m_w == 1) {
        cout << "Yes\n";
    } else {
        f(k);
    }
}