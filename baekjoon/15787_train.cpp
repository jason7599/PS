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

int n_trains, trains[100'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_trains);
    REP(input()) {
        int cmd = input();
        int& t = trains[input()];
        if (cmd <= 2) {
            int x = input() - 1;
            if (cmd == 1) {
                t |= (1 << x);
            } else {
                t &= ~(1 << x);
            }
        } else {
            if (cmd == 3) {
                t <<= 1;
            } else {
                t >>= 1;
                t &= ~(1 << 19);
            }
        }
    }

    unordered_set<int> s;
    RANGE(i, 1, n_trains) {
        int t = trains[i] & ((1 << 20) - 1);
        s.insert(t);
    }

    print(s.size());
}