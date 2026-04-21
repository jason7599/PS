#include <bits/stdc++.h>
using namespace std;

void p(char c, int n) {
    cout << string(n, c);
}

void ps(int n) {
    p('*', n);
}

void pb(int n) {
    p(' ', n);
}

void pn() {
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    ps(n); pb(2 * n - 3); ps(n); pn();
    for (int i = 1; i < 2 * (n - 1); i++) {
        int t = i <= n - 1 ? i : 2 * (n - 1) - i;
        pb(t); ps(1); pb(n - 2); 
        if (i != n - 1) {
            ps(1);
            pb(2 * n - 3 - 2 * t);
        }
        ps(1); pb(n - 2); ps(1); pn();
    }
    ps(n); pb(2 * n - 3); ps(n); pn();
}
