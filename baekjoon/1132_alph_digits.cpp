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
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF}
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int c2i(char c) {
    return c - 'A';
}

bool nz[10]; // new zealand
int cnv[10];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<int, ll> cnts;
    FOR(i, input()) {
        string s = input<string>();
        nz[c2i(s.front())] = 1;
        for (ll j = s.length() - 1, d = 1; j >= 0; j--, d *= 10) {
            cnts[c2i(s[j])] += d;
        }
    }

    vector<pair<int, ll>> v(cnts.begin(), cnts.end());
    sort(v.begin(), v.end(), [](pair<int, ll>& lhs, pair<int, ll>& rhs) {
        return lhs.se > rhs.se;
    });
    // desc cnt

    int z = -1;
    if (v.size() == 10) { // have to assign zero
        for (int i = 9;; i--) {
            if (!nz[v[i].fi]) {
                z = v[i].fi;
                break;
            }
        }
    }

    int nx = 9;
    for (const auto& [n, cnt] : v) {
        if (n != z) {
            cnv[n] = nx--;
        }
    }

    ll ans = 0;
    for (const auto& [i, cnt] : cnts) {
        ans += cnv[i] * cnt;
    }

    print(ans);
}