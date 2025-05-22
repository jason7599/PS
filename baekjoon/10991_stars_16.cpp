#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0, b = n - 1; i < n; i++, b--) {
        cout << string(b, ' ');
        cout << '*';
        for (int j = 0; j < i; j++) {
            cout << " *";
        }
        cout << '\n';
    }
}
