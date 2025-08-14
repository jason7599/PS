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
queue<int> qs[2][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(ai, 2) {
        FOR(i, input(lens[ai])) {
            qs[ai][input()].push(i);
        }
    }

    int idxs[2]{};
    vector<int> ans;
    for (int mx = 100; mx > 0 && idxs[0] < lens[0] && idxs[1] < lens[1];) {
        for (; mx > 0; mx--) {
            FOR(ai, 2) {
                for (; qs[ai][mx].size() && qs[ai][mx].front() < idxs[ai]; qs[ai][mx].pop());
                if (qs[ai][mx].empty()) {
                    goto cont_mx;
                }
            }

            ans.push_back(mx);
            FOR(ai, 2) {
                idxs[ai] = qs[ai][mx].front() + 1;
            }
            break;

            cont_mx:;
        }
    }

    print(ans.size());
    for (int i : ans) {
        cout << i << ' ';
    } LF
}