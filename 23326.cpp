#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n_nodes, n_queries] = inputs<int, 2>();

    set<int> st;
    RANGE(n, 1, n_nodes) {
        if (input()) {
            st.insert(n);
        }
    }

    int pos = 1;
    REP(n_queries) {
        switch (input()) {
            case 1: {
                int x = input();
                if (st.count(x)) st.erase(x);
                else st.insert(x);
                break;
            } case 2: {
                pos = ((pos - 1) + input()) % n_nodes + 1;
                break;
            } case 3: {
                auto it = st.lower_bound(pos);
                int t;
                if (it == st.end()) {
                    if (st.empty()) {
                        print(-1);
                        continue;
                    }
                    t = *st.begin();
                } else {
                    t = *it;
                }
                print((t + n_nodes - pos) % n_nodes);
            }
        }
    }
}