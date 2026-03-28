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

const int MAX_VAL = 1000;

bool not_prime[MAX_VAL + 1];
vector<int> primes;

void init_primes() {
    not_prime[1] = true;
    for (int i = 2; i * i <= MAX_VAL; i++) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= MAX_VAL; j += i) {
            not_prime[j] = true;
        }
    }

    primes.push_back(2);
    for (int i = 3; i <= MAX_VAL; i += 2) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
    }
}

bool bt(int v, int pi, int c0, int c1) {
    if (c1) {
        if (v && !not_prime[v]) {
            vector<int> t = {c0, c1, v};
            sort(t.begin(), t.end());
            for (int i : t) {
                cout << i << ' ';
            }
            LF;
            return true;
        }
        return false;
    }

    if (pi >= primes.size() || primes[pi] > v) {
        return false;
    }

    if (bt(v - primes[pi], pi, c0 ? c0 : primes[pi], c0 ? primes[pi] : 0)) {
        return true;
    }

    return bt(v, pi + 1, c0, c1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    init_primes();

    REP(input()) {
        if (!bt(input(), 0, 0, 0)) {
            print(0);
        }
    }
}