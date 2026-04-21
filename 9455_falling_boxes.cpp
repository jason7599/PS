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

stack<int> box_ys[100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    REP(input()) {
        auto [h, w] = inputs<int, int>();
        FOR(y, h) {
            FOR(x, w) {
                if (input()) {
                    box_ys[x].push(y);
                }
            }
        }

        int ans = 0;
        FOR(x, w) {
            for (int b = h - 1; box_ys[x].size(); box_ys[x].pop(), b--) {
                ans += b - box_ys[x].top();
            }
        }

        print(ans);
    }
}