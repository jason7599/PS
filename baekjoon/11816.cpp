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

int conv8(const string& s) {
    int x = 0;
    RANGE(i, 1, s.length() - 1) {
        x <<= 3;
        x += s[i] - '0';
    }
    return x;
}

int conv16(const string& s) {
    int x = 0;
    RANGE(i, 2, s.length() - 1) {
        x <<= 4;
        x += isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
    }
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s = input<string>();
    if (s[0] == '0' && s.length() > 1) {
        if (s[1] == 'x') {
            print(conv16(s));
        } else {
            print(conv8(s));
        }
    } else {
        print(s);
    }
}