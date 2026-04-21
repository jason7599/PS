#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const pii DIRS[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int m_height, m_width;
int m_grid[50][50];

int max_path_len;
int max_path_val;

void func(int y, int x) {
    static int visited[50][50];
    static int next_visit_id = 1;

    int visit_id = visited[y][x] = next_visit_id++;
    queue<pii> q({{y, x}});

    int start_val = m_grid[y][x];
    int end_val;
    int len = 0;
    for (int q_size; (q_size = q.size()); len++) {
        end_val = 0;
        while (q_size--) {
            auto [y, x] = q.front();
            q.pop();

            end_val = max(end_val, m_grid[y][x]);

            for (const auto [dy, dx] : DIRS) {
                int ny = y + dy;
                int nx = x + dx;

                if (ny < 0 || ny >= m_height || nx < 0 || nx >= m_width) {
                    continue;
                }

                if (!m_grid[ny][nx]) {
                    continue;
                }

                if (visited[ny][nx] != visit_id) {
                    visited[ny][nx] = visit_id;
                    q.push({ny, nx});
                }
            }
        }
    }

    if (len > max_path_len) {
        max_path_len = len;
        max_path_val = start_val + end_val;
    } else if (len == max_path_len) {
        max_path_val = max(max_path_val, start_val + end_val);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m_height >> m_width;
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            cin >> m_grid[y][x];
        }
    }

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            if (m_grid[y][x]) {
                func(y, x);
            }
        }
    }

    cout << max_path_val << '\n';
}