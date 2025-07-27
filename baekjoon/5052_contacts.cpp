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

string raw[10'000];

struct Node {
    unique_ptr<Node> subs[10] = {};
    bool end = 0;
};

/**
fail cases:
1. insert 13 to 134 -> final node('3') exists. So we check if we manually created the last node.
2. insert 134 to 13 -> node on path exists and is marked as end. Can be easily checked while iterating
*/

bool try_add(Node* node, const string& str) {
    bool b = 0; // did we allocate our last node? i.e. was the last node NOT already present?
    for (char c : str) {
        int i = c - '0';
        if ((b = !node->subs[i])) {
            node->subs[i] = make_unique<Node>();
        }
        node = node->subs[i].get();
        if (node->end) return 0;
    }
    if (!b) return 0;

    node->end = 1;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    REP(input()) {
        int n;
        FOR(i, input(n)) input(raw[i]);

        Node root;
        bool res = 1;
        FOR(i, n) {
            if (!try_add(&root, raw[i])) {
                res = 0;
                break;
            }
        }

        print(res ? "YES" : "NO");
    }
}