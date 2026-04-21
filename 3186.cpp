#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define DBG(x) cerr << #x << " = " << x << '\n'
using namespace std;
using pii = pair<int, int>;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

vector<pair<bool, int>> parse(const string& s) {
    vector<pair<bool, int>> res;

    int i = 0;
    bool b = s.front() == '1';
    while (i < s.length()) {
        int t = s.find_first_not_of('0' + b, i + 1);
        if (t == string::npos) {
            t = s.length();
        }
        res.push_back({b, t - i});
        i = t;
        b = !b;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [use_thr, idle_thr, end_time] = inputs<int, 3>();

    int time = 0;
    bool waiting_flush = false;
    int last_used_time;
    bool no_flush = true;
    for (auto [used, dur] : parse(input<string>())) {
        if (used) {
            if (dur >= use_thr) {
                waiting_flush = true;
                no_flush = false;
            }
            last_used_time = time + dur;
        } else {
            if (dur >= idle_thr) {
                if (waiting_flush) {
                    print(last_used_time + idle_thr);
                    waiting_flush = false;
                }
            }
        }

        time += dur;
    }

    if (no_flush) {
        print("NIKAD");
    } else if (waiting_flush) {
        print(last_used_time + idle_thr);
    }
}