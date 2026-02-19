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

const string S1 = "Messi";
const string S2 = S1 + " Gimossi";

int get_len(int n) {
    static int dp[41];

    if (n <= 2) return (n == 1 ? S1 : S2).length();

    int& res = dp[n];
    if (res) return res;

    return res = get_len(n - 1) + 1 + get_len(n - 2);
}

char f(int digit, int n) {
    if (n <= 2) return (n == 1 ? S1 : S2)[digit - 1];

    int l = get_len(n - 1);

    if (digit <= l) return f(digit, n - 1);

    if (digit == l + 1) return ' ';

    return f(digit - l - 1, n - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int digit = input(), n;
    for (n = 1; get_len(n) < digit; n++);

    char c = f(digit, n);
    if (c == ' ') {
        print(S1, S2);
    } else {
        print(c);
    }
}