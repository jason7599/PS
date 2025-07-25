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
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/**
goal:
    while minimizing sum(cost), make sum(use) >= alloc
    - sum(use) >= alloc
    - min(cost)
    
ideas:
    n_proc <= 100, cost <= 100...
    total cost <= 10'000.
    dp[proc_idx][total_cost] = max_alloc?

    then:
        the first total_cost c that satisfies dp[c] >= alloc becomes the answer
*/

int n_procs, targ_alloc;
int procs[100][2];
int dp[100][10'001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    input(n_procs, targ_alloc);
    FOR(i, 2) {
        FOR(j, n_procs) {
            
        }
    }

}