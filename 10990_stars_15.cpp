#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;

    for (int b = n - 1, g = -1, i = 0; i < n; i++, b--, g += 2) {
        cout << string(b, ' ');
        cout << '*';
        if (i) {
            cout << string(g, ' ');
            cout << '*';
        }
        cout << '\n';
    }
}
