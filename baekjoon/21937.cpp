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
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF}
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
vector<int> pre[100'001];
bool vis[100'001];

int dfs(int x) {
    vis[x] = 1;
    int res = 0;
    for (int p : pre[x]) {
        if (!vis[p]) {
            res += 1 + dfs(p);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n);
    REP(input()) {
        int a, b;
        input(a, b);
        pre[b].push_back(a);
    }
    print(dfs(input()));
}