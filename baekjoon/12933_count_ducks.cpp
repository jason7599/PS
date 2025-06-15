#include <bits/stdc++.h>
using namespace std;

int qtoi(char c) {
    switch (c) {
        case 'q': return 0;
        case 'u': return 1;
        case 'a': return 2;
        case 'c': return 3;
        case 'k': return 4;
    }
    return -91748912;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string str;
    cin >> str;

    int quack[4] = {};
    int n_quacks = 0; // unfinished
    int n_ducks = 0; // finished

    for (char c : str) {
        int t = qtoi(c);
        if (t == 0) {
            if (n_ducks <= n_quacks) { // only when there are no idle ducks
                n_ducks++;
            }
            n_quacks++;
        } else if (t == 4) {

        }
    }

    if (n_quacks) {
bad:
        cout << -1 << '\n';
    } else {
        cout << n_ducks << '\n';
    }
}
