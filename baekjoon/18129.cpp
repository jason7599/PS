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
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string str;
    int k;

    input(str, k);

    bool vis[27] = {};
    str.push_back('a' + 26);

    char p = tolower(str.front());
    int cnt = 0;
    for (char c : str) {
        c = tolower(c);
        if (c != p) {
            if (!vis[p - 'a']) {
                if (cnt >= k) {
                    cout << 1;
                } else {
                    cout << 0;
                }
                vis[p - 'a'] = 1;
                p = c;
                cnt = 1;
            }
        } else {
            cnt++;
        }
    }
    cout << '\n';
}