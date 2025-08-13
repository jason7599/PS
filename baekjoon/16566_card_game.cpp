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

int cards[(int)4e6];
int nxts[(int)4e6];

int find_nxt(int i) {
    if (nxts[i] != i) {
        nxts[i] = find_nxt(nxts[i]);
    }
    return nxts[i];
}

void make_union(int a, int b) {
    a = find_nxt(a);
    b = find_nxt(b);
    nxts[min(a, b)] = max(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto [mx_card, n_cards, n_turns] = inputs<int, int, int>();

    FOR(i, n_cards) {
        input(cards[i]);
        nxts[i] = i;
    }

    sort(cards, cards + n_cards);

    REP(n_turns) {
        int i = find_nxt(upper_bound(cards, cards + n_cards, input()) - cards);
        print(cards[i]);
        if (i + 1 < n_cards) {
            make_union(i, i + 1);
        }
    }
}