#include <bits/stdc++.h>
using namespace std;

int m_h, m_w;
int m_vals[101][101];
int m_sums[101][101];

#define PRINT(x) cout << x << '\n';

int get_sum(int y0, int x0, int y1, int x1) {
    return
        m_sums[y1][x1]
        - m_sums[y0 - 1][x1]
        - m_sums[y1][x0 - 1]
        + m_sums[y0 - 1][x0 - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> m_h >> m_w;
    for (int y = 1; y <= m_h; y++) {
        for (int x = 1; x <= m_w; x++) {
            int val;
            cin >> val;
            m_vals[y][x] = val;
            m_sums[y][x] = 
                m_sums[y - 1][x]
                + m_sums[y][x - 1]
                - m_sums[y - 1][x - 1]
                + val;
        }
    }

    int max_beauty = -1000 * m_h * m_w;
    
    for (int y0 = 1; y0 <= m_h - 1; y0++) {
        int row0_val = get_sum(y0, 1, y0, m_w);
        for (int y1 = y0 + 1; y1 <= m_h; y1++) {
            int row1_val = get_sum(y1, 1, y1, m_w);
            for (int x0 = 1; x0 <= m_w - 1; x0++) {
                int col0_val = get_sum(1, x0, m_h, x0);
                for (int x1 = x0 + 1; x1 <= m_w; x1++) {
                    int col1_val = get_sum(1, x1, m_h, x1);
                    int road_val =
                        row0_val
                        + row1_val
                        + col0_val
                        + col1_val
                        - m_vals[y0][x0]
                        - m_vals[y0][x1]
                        - m_vals[y1][x0]
                        - m_vals[y1][x1];
                    int area_val = (y1 - y0 - 1) * (x1 - x0 - 1);
                    int beauty = road_val + area_val;
                    max_beauty = max(max_beauty, beauty);
                }
            }
        }
    }

    cout << max_beauty << '\n';
}
