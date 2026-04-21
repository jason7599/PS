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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    priority_queue<int> pos_q; // x > 1
    priority_queue<int> neg_q; // x < 0
    int n0 = 0, n1 = 0;

    REP(input()) {
        int x = input();
        if (x < 0) {
            neg_q.push(-x);
        } else if (x == 0) {
            n0++;
        } else if (x == 1) {
            n1++;
        } else {
            pos_q.push(x);
        }
    }

    int ans = n1; // always better to add 1 instead of mult
    REP(pos_q.size() / 2) {
        int a = pos_q.top();
        pos_q.pop();
        ans += a * pos_q.top();
        pos_q.pop();
    }
    if (pos_q.size()) {
        ans += pos_q.top();
    }

    REP(neg_q.size() / 2) {
        int a = neg_q.top();
        neg_q.pop();
        ans += a * neg_q.top();
        neg_q.pop();
    }
    if (neg_q.size() && !n0) {
        ans -= neg_q.top();
    }

    print(ans);
}