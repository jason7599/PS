#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n, dmap[101][101];

void floyd() {
    RANGE(k, 1, n) {
        RANGE(i, 1, n) {
            RANGE(j, 1, n) {
                dmap[i][j] = min(dmap[i][j], 
                    dmap[i][k] + dmap[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int m;
    input(n, m);
    RANGE(i, 1, n) {
        fill(&dmap[i][1], &dmap[i][n + 1], 1e9);
        dmap[i][i] = 0;
    }

    REP(m) {
        int a, b;
        input(a, b);
        dmap[a][b] = 1;
        dmap[b][a] = 1;
    }

    floyd();

    int min_cnt = INT_MAX, ans;
    RANGE(i, 1, n) {
        int cnt = 0;
        RANGE(j, 1, n) {
            cnt += dmap[i][j];
        }
        if (cnt < min_cnt) {
            min_cnt = cnt;
            ans = i;
        }
    }

    print(ans);
}