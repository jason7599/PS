#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define LF {cout << '\n';}
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF }
template<typename T> T upmax(T& v, const T& other) { v = max(v, other); return v; }
template<typename T> T upmin(T& v, const T& other) { v = min(v, other); return v; }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int lens[2];
int arrs[2][20];

int comb_lens[2]{-1, -1};
int combs[2][1 << 20];

void bt_combs(int ai, int i, int s) {
    if (i == lens[ai]) {
        if (comb_lens[ai] == -1) {
            comb_lens[ai] = 0;
        } else {
            combs[ai][comb_lens[ai]++] = s;
        }
        return;
    }

    bt_combs(ai, i + 1, s);
    bt_combs(ai, i + 1, arrs[ai][i] + s);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n, s] = inputs<int, int>();

    if (n == 1) {
        print(input() == s);
        return 0;
    }

    lens[0] = n / 2;
    lens[1] = n - lens[0];

    FOR(ai, 2) {
        FOR(i, lens[ai]) {
            input(arrs[ai][i]);
        }
    }

    FOR(ai, 2) {
        bt_combs(ai, 0, 0);
        sort(combs[ai], combs[ai] + comb_lens[ai]);
    }

    ll ans = 0;
    for (int l = 0, r = comb_lens[1] - 1; l < comb_lens[0] && r >= 0;) {
        int sm = combs[0][l] + combs[1][r];
        if (sm < s) {
            l++;
        } else if (sm > s) {
            r--;
        } else {
            int l_cnt = 1, r_cnt = 1;
            for (; l + l_cnt < comb_lens[0] && combs[0][l + l_cnt] == combs[0][l]; l_cnt++);
            for (; r - r_cnt >= 0 && combs[1][r - r_cnt] == combs[1][r]; r_cnt++);

            ans += (ll)l_cnt * r_cnt;
            
            l += l_cnt;
            r -= r_cnt;
        }
    }

    FOR(ai, 2) {
        for (int t = lower_bound(combs[ai], combs[ai] + comb_lens[ai], s) - combs[ai];
            t < comb_lens[ai] && combs[ai][t] == s; t++) {
            ans++;
        }
    }

    print(ans);
}