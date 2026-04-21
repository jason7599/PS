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

ll arr[1 << 10];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n = input();
    if (n >= 1 << 10) {
        print(-1);
        return 0;
    }

    RANGE(i, 1, (1 << 10) - 1) {
        ll& v = arr[i - 1];
        for (int b = 9; b >= 0; b--) {
            if ((i & (1 << b))) {
                v *= 10;
                v += b;
            }
        }
    }

    sort(arr, arr + (1 << 10));

    print(arr[n]);
}