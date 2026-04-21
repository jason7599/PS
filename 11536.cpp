#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<string> names(n);
    for (auto& name : names) {
        cin >> name;
    }

    int t = 0;
    for (int i = 1; i < n; i++) {
        if (names[i] > names[i - 1]) {
            t++;
        } else {
            t--;
        }
        if (abs(t) != i) {
            break;
        }
    }

    if (t == n - 1) {
        cout << "INCREASING\n";
    } else if (t == 1 - n) {
        cout << "DECREASING\n";
    } else {
        cout << "NEITHER\n";
    }
}
