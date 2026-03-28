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
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

/*
i is at '1'
locate t = '0'

if len < use_thr: no transitions
else: now entered use mode

if no transition, i.e., still in idle mode, repeat process this whole process
if now in use mode, search 
*/

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [use_thr, idle_thr, N] = inputs<int, 3>();
    auto s = input<string>();

    bool init = true; // todo: simplify
    bool idle = true;

    for (int i = 0;;) {
        int t = s.find_first_of('1', i);
        if (t == string::npos) {
            if (init) {
                print("NIKAD");
            }
            break;
        }

        if (t - i >= idle_thr) {
            if (!idle) {
                idle = true;
                print(t);
            }
        }

        init = false;

        i = t; // i is now at '1'

        t = s.find_first_of('0', i + 1);
        if (t == string::npos) {
            print(s.length() + idle_thr);
            break;
        }

        if (t - i >= use_thr) {
            idle = false;
        }

        i = t; // i is now at '0'
    }
}