#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        string n;
        cin >> n;
        if (!next_permutation(n.begin(), n.end())) {
            cout << "BIGGEST\n";
        } else {
            cout << n << '\n';
        }
    }
}