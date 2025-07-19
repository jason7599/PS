#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int roots[1'000'001];

int get_root(int n) {
    if (roots[n] != n) {
        roots[n] = get_root(roots[n]);
    }
    return roots[n];
}

void make_union(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    roots[min(a, b)] = max(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, n_ops;
    cin >> n >> n_ops;

    iota(roots, roots + n + 1, 0);

    while (n_ops--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op) {
            if (get_root(a) == get_root(b)) {
                PRINT("YES")
            } else {
                PRINT("NO")
            }
        } else {
            make_union(a, b);
        }
    }
}