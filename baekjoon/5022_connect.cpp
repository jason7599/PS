#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const pii DIRS[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_height, g_width;
int grid_used[101][101];
int visited[101][101];
int prev_dirs[101][101];

int& get_cell(int a[][101], pii p) {
    return a[p.first][p.second];
}

void input_point(pii& p) {
    cin >> p.first >> p.second;
}

int connect_optimal(pii src, pii dst, int id) {
    int t = 0;
    auto [y, x] = src;
    while (y != dst.first) {
        

    }
}

int connect(pii src, pii dst, int id) {
    queue<pii> q({src});
    get_cell(visited, src) = id;

    int len = 0;
    for (int q_size; (q_size = q.size());) {
        while (q_size--) {
            pii cur = q.front();
            q.pop();

            if (cur == dst) {
                goto good;
            }


        }
        len++;
    }

    return -1;

good:
    return len + 1;   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_height >> g_width;

    pii p1_src, p1_dst, p2_src, p2_dst;
    input_point(p1_src);
    input_point(p1_dst);
    input_point(p2_src);
    input_point(p2_dst);

}