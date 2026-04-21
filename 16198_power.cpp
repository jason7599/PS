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

int n, arr[10];
bool used[10];

int f(int n_used) {
    if (n_used == n - 2) {
        return 0;
    }

    vector<int> idxs(n - n_used);
    for (int i = 0, t = 0; i < n && t < idxs.size(); i++) {
        if (!used[i]) {
            idxs[t++] = i;
        }
    }

    int res = 0;
    RANGE(i, 1, idxs.size() - 2) {
        used[idxs[i]] = 1;
        upmax(res, arr[idxs[i - 1]] * arr[idxs[i + 1]] + f(n_used + 1));
        used[idxs[i]] = 0;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) { 
        input(arr[i]);
    }

    print(f(0));
}