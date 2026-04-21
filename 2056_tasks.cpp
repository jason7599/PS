#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(n) for(int i = n; i > 0; i--)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> void input(T& t) { cin >> t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

int n_tasks, task_times[10'001];
vector<int> prereqs[10'001];
bool vis[10'001];
int dp[10'001];

void topo_sort(int t, stack<int>& stk) {
    vis[t] = 1;
    for (int p : prereqs[t]) {
        if (!vis[p]) {
            topo_sort(p, stk);
        }
    }
    stk.push(t);
}

int get_min_time(int t) {
    int& res = dp[t];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (int p : prereqs[t]) {
        res = max(res, get_min_time(p));
    }

    res += task_times[t];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input(n_tasks);
    RANGE(t, 1, n_tasks) {
        input(task_times[t]);
        dp[t] = -1;
        REP(input()) {
            prereqs[t].push_back(input());
        }
    }

    stack<int> stk;
    RANGE(t, 1, n_tasks) {
        if (!vis[t]) {
            topo_sort(t, stk);
        }
    }

    int ans = 0;
    for(; !stk.empty(); stk.pop()) {
        int t = stk.top();
        if (dp[t] == -1) {
            ans = max(ans, get_min_time(t));
        }
    }

    print(ans);
}