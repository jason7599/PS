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

int arr[500'000];
int asc[500'000]; // asc[i] = len of increasing seq(continuous) before arr[i]

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n = input();
    FOR(i, n) {
        input(arr[i]);
        if (i) {
            if (arr[i] > arr[i - 1]) {
                asc[i] = asc[i - 1] + 1; 
            } else if (arr[i] < arr[i - 1]) {
                asc[i] = 0;
            } else {
                asc[i] = asc[i - 1];
            }
        }
    }

    int ans = 0;
    for (int i = n - 1, dsc = 0; i >= 0; i--) {
        if (i + 1 < n) {
            if (arr[i] > arr[i + 1]) {
                dsc++;
            }
            else if (arr[i] < arr[i + 1]) {
                dsc = 0;
            }
        }
        upmax(ans, max(asc[i], dsc) + 1);
    }
    print(ans);
}