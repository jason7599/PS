#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// D, R, U, L
const pii MOVES[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int m_h, m_w, maze[150][150], dmap[150][150];

/**
 * 
 * 문제가 뭐냐면
 * 방향 전환을 할 때 L을 쓸지 R을 쓸지 그리디하게 정할 수 없어
 * 예를 들어 180도 전환을 해야할때 어떤걸 쓸거야?
 * 모르잖아
 * 
 * 그럼 각 지점마다 목적지까지 가기 위해 필요한 최소 L의 개수와 R의 개수를 따로 저장을 해둘까
 * 즉 목적지 기준 다익스트라?
 */

void f(int k) {
    if (m_h * m_w == 1) {
        cout << "Yes\n";
        return;
    }

    priority_queue<pair<int, pair<pii, pii>>> pq;
    pq.push({0, {{0, 0}, {k, k}}});
    dmap[0][0] = 0;

    auto push = [&](int y, int x, int d, int nx_cost, int l, int r) {
        y += MOVES[d].first;
        x += MOVES[d].second;

        if (y < 0 || y >= m_h || x < 0 || x >= m_w) {
            return;
        }

        if (y == m_h - 1 && x == m_w - 1) {
            cout << "Yes\n";
            exit(0);
        }

        if (nx_cost < dmap[y][x]) {
            dmap[y][x] = nx_cost;
            pq.push({-nx_cost, {{y, x}, {l, r}}});
        }
    };

    while (pq.size()) {
        int cur_cost = -pq.top().first;
        const auto [y, x] = pq.top().second.first;
        const auto [l, r] = pq.top().second.second;
        pq.pop();

        if (cur_cost > dmap[y][x]) {
            continue;
        }

        push(y, x, maze[y][x], cur_cost, l, r);

        if (l || r >= 3) {
            push(y, x, (maze[y][x] + 1) % 4, cur_cost + (l ? 1 : 3), l ? l - 1 : 0, l ? r : r - 3);
        }

        if (min(l, r) >= 2) {

        }

        if (r || l >= 3) {
            push(y, x, (maze[y][x] + 3) % 4, cur_cost + (r ? 1 : 3), r ? l : l - 3, r ? r - 1 : 0);
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
            dmap[y][x] = INT_MAX;
        }
    }

    f(k);
}