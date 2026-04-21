#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string n;
    cin >> n;

    int i = 0;
    int p7 = -1; // last appearance of 7
    for (; n[i] == '4' || n[i] == '7'; i++) {
        if (n[i] == '7') {
            p7 = i;
        }
    }

    if (i == n.length()) {
        cout << n;
    } else {
        if (n[i] > '4') {
            cout << n.substr(0, i);
            cout << (n[i] > '7' ? '7' : '4');
            cout << string(n.length() - i - 1, '7');
        } else {
            if (p7 != -1) {
                cout << n.substr(0, p7);
                cout << '4';
                cout << string(n.length() - p7 - 1, '7');
            }
            else {
                cout << string(n.length() - 1, '7');
            }
        }
    }
    cout << '\n';
}
