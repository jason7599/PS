#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int g_h, g_w;
vector<int> spots[100];

int f() {
    int cnt = 0;
    for (int y = 0, x = 0; y < g_h; y++) {
        vector<int>& arr = spots[y];
        if (arr.empty()) {
            continue;
        }
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) {
            continue;
        }
        
        cnt += arr.end() - it;
        x = arr.back();
        arr.erase(it, arr.end());
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;
    int n_spots = 0;
    FOR(y, g_h) {
        FOR(x, g_w) {
            int t;
            cin >> t;
            if (t) {
                n_spots++;
                spots[y].push_back(x);
            }
        }
    }

    int ans = 0;
    for (int cnt = 0; cnt < n_spots; ans++) {
        cnt += f();   
    }

    PRINT(ans)
}