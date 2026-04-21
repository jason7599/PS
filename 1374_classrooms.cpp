#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
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

int n;
pii arr[100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, input(n)) {
        input();
        input(arr[i].fi, arr[i].se);
    }

    sort(arr, arr + n);

    priority_queue<int> pq; // min-heap on ending time
    FOR(i, n) {
        if (!pq.empty() && -pq.top() <= arr[i].fi) {
            pq.pop();
        }
        pq.push(-arr[i].se);
    }

    print(pq.size());
}