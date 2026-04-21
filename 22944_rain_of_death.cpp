#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int g_size, init_umb_hp;
int n_umbs;
pii umbs_pos[10];

int l1_dist(pii src, pii dst) {
    return abs(src.first - dst.first) + abs(src.second - dst.second);
}

int f(pii src, pii dst, int hp, int umb_hp, int umbs_mask) {
    int dst_dist = l1_dist(src, dst);
    if (dst_dist <= hp + umb_hp) {
        return dst_dist;
    }

    int res = INT_MAX;
    for (int u = 0; u < n_umbs; u++) {
        if (umbs_mask & (1 << u)) {
            continue;
        }
        int dist = l1_dist(src, umbs_pos[u]);
        if (dist <= hp + umb_hp) {
            int nx_hp = hp - max(0, dist - umb_hp - 1);
            int t = f(umbs_pos[u], dst, nx_hp, init_umb_hp - 1, umbs_mask | (1 << u));
            if (t != -1) {
                res = min(res, dist + t);
            }
        }
    }

    return res != INT_MAX ? res : -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int init_hp;
    cin >> g_size >> init_hp >> init_umb_hp;

    pii src, dst;
    for (int y = 0; y < g_size; y++) {
        for (int x = 0; x < g_size; x++) {
            char c;
            cin >> c;
            if (c == 'S') {
                src = {y, x};
            } else if (c == 'E') {
                dst = {y, x};
            } else if (c == 'U') {
                umbs_pos[n_umbs++] = {y, x};
            }
        }
    }

    cout << f(src, dst, init_hp, 0, 0) << '\n';
}