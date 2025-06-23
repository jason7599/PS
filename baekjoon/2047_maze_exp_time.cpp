#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int m_h, m_w;
bool m_walls[96][96];

bool is_oob(int y, int x) {
    return y < 0 || y >= m_h || x < 0 || x >= m_w;
}

/**
 * 갈림길 만나면
 * p 위치에서 방향 a랑 b가 있다고 하자
 * p에서 a 방향으로 끝까지 ㄱ
 */

float solve(pii start, pii dest) {
    float res = 0;



    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        cin >> m_h >> m_w;
        pii start, dest;
        for (int y = 0; y < m_h; y++) {
            for (int x = 0; x < m_w; x++) {
                char c;
                cin >> c;
                if (c == 's') {
                    start = {y, x};
                } else if (c == 't') {
                    dest = {y, x};
                }
                m_walls[y][x] = c == '#';
            }
        }
    }
}
