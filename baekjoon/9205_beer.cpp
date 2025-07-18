#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n_stores;
pii stores[100];
bool vis[100];

void pii_in(pii& p) {
    cin >> p.first >> p.second;
}

int man_dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool dfs(pii cur, pii dst) {
    if (man_dist(cur, dst) <= 20 * 50) {
        return 1;
    }
    FOR(i, n_stores) {
        if (!vis[i] && man_dist(cur, stores[i]) <= 20 * 50) {
            vis[i] = 1;
            if (dfs(stores[i], dst)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        cin >> n_stores;
        pii src, dst;
        pii_in(src);
        FOR(i, n_stores) {
            pii_in(stores[i]);
            vis[i] = 0;
        }
        pii_in(dst);

        if (dfs(src, dst)) {
            PRINT("happy")
        } else {
            PRINT("sad")
        }
    }
}