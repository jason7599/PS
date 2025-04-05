#include <bits/stdc++.h>

using namespace std;

int n_vals, bit_len;
int vals[1001];
int prevs[1001];
unordered_map<int, int> vals_idx;

bool bfs(int src, int dst) {
    queue<int> q({src});
    prevs[src] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == dst) {
            return 1;
        }

        for (int b = 0; b < bit_len; b++) {
            int next_val = vals[cur] ^ (1 << b);
            if (vals_idx.count(next_val)) {
                int next = vals_idx[next_val];
                if (!prevs[next]) {
                    prevs[next] = cur;
                    q.push(next);
                }
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n_vals >> bit_len;
    for (int i = 1; i <= n_vals; i++) {
        int val = 0;
        for (int b = 0; b < bit_len; b++) {
            char c;
            cin >> c;
            val = val * 2 + (c == '1');
        }
        vals[i] = val;
        vals_idx[val] = i;
    }

    int src, dst;
    cin >> src >> dst;

    if (bfs(src, dst)) {
        stack<int> path;
        for (int n = dst; n != -1; n = prevs[n]) {
            path.push(n);
        }
        while (!path.empty()) {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}