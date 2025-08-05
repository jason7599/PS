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
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

string s;
int n_words;
pair<string, int> words[100];

int dp[1000];

int f(int idx) {
    if (idx == s.length()) {
        return 0;
    }

    int& res = dp[idx];
    if (res) {
        return res;
    }

    res = 1 + f(idx + 1);
    FOR(i, n_words) {
        const string& w = words[i].fi;
        if (idx + w.length() > s.length()) {
        cont:
            continue;
        }
        FOR(j, w.length()) {
            if (s[idx + j] != w[j]) {
                goto cont;
            }
        }
        upmax(res, words[i].se + f(idx + w.length()));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(s);
    REP(input()) {
        auto [w, x] = inputs<string, int>();
        if (w.length() < x) {
            words[n_words++] = {w, x};
        }
    }

    print(f(0));
}