#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n;
bool cop[100'001];
bool vis[100'001];

int f(int src, int dst, int r_jump, int l_jump) {
    vis[src] = 1;
    queue<int> q({src});

    auto push = [&](int x) {
        if (x == dst) {
            return 1;
        }
        if (0 < x && x <= n && !cop[x] && !vis[x]) {
            vis[x] = 1;
            q.push(x);
        }
        return 0;
    };

    for (int moves = 1, q_size; (q_size = q.size()); moves++) {
        while (q_size--) {
            int cur = q.front();
            q.pop();
            if (push(cur + r_jump) || push(cur - l_jump)) {
                return moves;
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int src, dst, r_jump, l_jump, n_cops;
    cin >> n >> src >> dst >> r_jump >> l_jump >> n_cops;
    while (n_cops--) {
        int x;
        cin >> x;
        cop[x] = 1;
    }

    int t = f(src, dst, r_jump, l_jump);
    if (t == -1) {
        cout << "BUG FOUND\n";
    } else {
        cout << t << '\n';
    }
}