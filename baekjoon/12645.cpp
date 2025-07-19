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
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }
template<typename T> void println(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void println(const T& t, const Args&... args) { print(t, args...); print('\n'); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    input(n_tc);
    RANGE(tc, 1, n_tc) {
        string s;
        input(s);
        cout << "Case #" << tc << ": "; 
        if (next_permutation(s.begin(), s.end())) {
            println(s);
        } else {
            char m = '9';
            bool z = 0;
            for (char c : s) {
                if (c == '0') {
                    z = 1;
                } else {
                    m = min(m, c);
                }
            }
        }
    }
}