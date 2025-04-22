#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int m_height, m_width;

/**
 * 바깥쪽서부터 파고 들어오면 어떨까.
 */

bool is_oob(int y, int x) {
    return y < 0 || y >= m_height || x < 0 || x >= m_width;
}

bool is_border(int y, int x) {
    return !y || y == m_height - 1 || !x || x == m_width - 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m_height >> m_width;
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            char c;
            cin >> c;
        }
    }
}