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

struct FileName {
    string name, ext;
};

FileName file_names[(int)2e5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [n_files, n_exts] = inputs<int, int>();
    cin.ignore();
    FOR(i, n_files) {
        getline(cin, file_names[i].name, '.');
        getline(cin, file_names[i].ext);
    }

    unordered_set<string> known_exts;
    REP(n_exts) {
        known_exts.emplace(input<string>());
    }

    sort(file_names, file_names + n_files, [&](FileName& lhs, FileName& rhs) {
        if (lhs.name == rhs.name) {
            int lf = known_exts.count(lhs.ext);
            int rf = known_exts.count(rhs.ext);
            if (lf == rf) {
                return lhs.ext < rhs.ext;
            }
            return lf > rf;
        }
        return lhs.name < rhs.name;
    });

    FOR(i, n_files) {
        cout << file_names[i].name << '.' << file_names[i].ext << '\n';
    }
}