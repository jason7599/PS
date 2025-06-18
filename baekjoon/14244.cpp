#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_node, n_leaf;
    cin >> n_node >> n_leaf;

    cout << "0 1\n";
    cout << "1 2\n";

    int i = 3;
    for (; i <= n_leaf; i++) {
        cout << "1 " << i << '\n';
    }

    for (; i < n_node; i++) {
        cout << i - 1 << ' ' << i << '\n';
    }
}
