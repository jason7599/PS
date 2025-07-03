#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_size, grid[2001][2001];
int n_civs, roots[100'001];
queue<pii> civs[100'001];
int n_merge;

// void print_grid() {
//     for (int y = 1; y <= g_size; y++) {
//         for (int x = 1; x <= g_size; x++) {
//             if (grid[y][x]) {
//                 cout << grid[y][x];
//             } else {
//                 cout << '.';
//             }
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }

bool is_oob(int y, int x) {
    return y <= 0 || x <= 0 || y > g_size || x > g_size;
}

int find_root(int n) {
    if (roots[n] == n) {
        return n;
    }
    return roots[n] = find_root(roots[n]);
}

bool make_union(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) {
        return 0;
    }
    roots[min(a, b)] = max(a, b);
    return ++n_merge == n_civs - 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_size >> n_civs;
    for (int i = 1; i <= n_civs; i++) {
        int y, x;
        cin >> y >> x;
        grid[y][x] = i;
        civs[i].push({y, x});
        roots[i] = i;
    }

    for (int i = 1; i <= n_civs; i++) {
        const auto& [y, x] = civs[i].front();
        for (const auto& [dy, dx] : DIRS) {
            int ny = y + dy;
            int nx = x + dx;
            if (!is_oob(ny, nx) && grid[ny][nx]) {
                if (make_union(i, grid[ny][nx])) {
                    cout << 0 << '\n';
                    return 0;
                }
            }
        }
    }

    for (int time = 1;; time++) {
        // print_grid();
        for (int i = 1; i <= n_civs; i++) {
            queue<pii>& q = civs[i];
            for (int q_size = q.size(); q_size; q_size--) {
                const auto [y, x] = q.front();
                q.pop();

                for (const auto& [dy, dx] : DIRS) {
                    int ny = y + dy;
                    int nx = x + dx;

                    if (is_oob(ny, nx)) {
                        continue;
                    }

                    if (grid[ny][nx]) {
                        if (make_union(i, grid[ny][nx])) {
                            cout << time << '\n';
                            return 0;
                        }
                    } else {
                        grid[ny][nx] = i;
                        q.push({ny, nx});
                    }

                    for (const auto& [ddy, ddx] : DIRS) {
                        int nny = ny + ddy;
                        int nnx = nx + ddx;

                        if (!is_oob(nny, nnx)) {
                            if (grid[nny][nnx] && make_union(i, grid[nny][nnx])) {
                                cout << time << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}