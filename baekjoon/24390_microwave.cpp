#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DBG(x) cerr << #x << " = " << x << '\n'
#define EE(p) (ll)(1e##p)
#define LF cout << '\n'
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

bool vis[361][2];

int bfs(int targ) {
    queue<pair<int, bool>> q;

    auto push = [&](int time, bool state) {
        if (!vis[time][state]) {
            vis[time][state] = 1;
            q.push({time, state});
        }
    };

    push(0, 0);

    for (int t = 0, q_size; (q_size = q.size()); t++) {
        REP(q_size) {
            int cur_time = q.front().fi;
            bool cur_state = q.front().se;
            q.pop();

            if (cur_time == targ && cur_state) {
                return t;
            }

            for (int nxt : {cur_time + 1, cur_time + 6, cur_time + 60}) {
                if (nxt <= targ) {
                    push(nxt, cur_state);
                }
            }

            if (cur_state) {
                push(cur_time + 3, 1);
            } else {
                push(cur_time ? cur_time : 3, 1);
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto s = input<string>();
    int targ = stoi(s.substr(0, 2)) * 6 + s[3] - '0';

    print(bfs(targ));
}