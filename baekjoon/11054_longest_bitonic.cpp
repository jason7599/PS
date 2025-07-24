#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for(int i = s, _e = e; i <= _e; i++)
#define REP(n) FOR(i, n)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }

int n, arr[1000];
int lis[1000], lds[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) {
        input(arr[i]);
        lis[i] = lds[i] = 1;
    }

    FOR(i, n) {
        int ri = n - i - 1;
        FOR(j, i) {
            if (arr[j] < arr[i]) {
                upmax(lis[i], 1 + lis[j]);
            }
            int rj = n - j - 1;
            if (arr[ri] > arr[rj]) {
                upmax(lds[ri], 1 + lds[rj]);
            }
        }
    }

    int ans = 0;
    FOR(i, n) {
        upmax(ans, lis[i] + lds[i] - 1);
    }

    print(ans);
}