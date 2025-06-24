#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> roots;

int find_root(int n) {
    if (roots[n] == n) {
        return n;
    }
    return roots[n] = find_root(roots[n]);
}

void make_union(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a != b) {
        roots[max(a, b)] = roots[min(a, b)];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_node;    
    cin >> n_node;

    roots.resize(1 + n_node);
    iota(roots.begin(), roots.end(), 0);

    int n_vis;
    cin >> n_vis;

    for (int i = 1; i <= n_node; i++) {
        for (int j = 1; j <= n_node; j++) {
            int b;
            cin >> b;
            if (b && i < j) {
                make_union(i, j);
            }
        }
    }

    vector<int> v(n_vis);
    for (int& i : v) {
        cin >> i;
    }

    int t = find_root(v.front());
    for (int i = 1; i < v.size(); i++) {
        if (find_root(v[i]) != t) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}
