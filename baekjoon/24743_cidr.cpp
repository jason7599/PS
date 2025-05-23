#include <bits/stdc++.h>
using namespace std;

int input() {
    int v;
    cin >> v;
    for (int i = 0, t; i < 3; i++) {
        cin.ignore();
        cin >> t;
        v <<= 8;
        v += t; 
    }
    return v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int mask = input(), len = 32;
    for (int i = 1; i < n; i++) {
        int t = input() ^ mask;
        int nlen = 0;
        for (; nlen < len && !(t >> (31 - nlen)); nlen++);
        len = nlen;
    }

    cout << len << '\n';
}