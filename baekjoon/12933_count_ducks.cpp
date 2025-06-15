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

    int quack[4] = {};  // quack[i] = # of ducks who made it to the i-th character of quack 
    int n_quacks = 0;   // # of unfinished quacks
    int n_ducks = 0;    // # total ducks, both idle and in quack

    for (char c : str) {
        int t = qtoi(c);
        if (t == 0) { // 'q'
            if (n_ducks == n_quacks) {  // there are no idle ducks
                n_ducks++;              // new duck should be introduced
            }
            n_quacks++;                 // quacking initiated
            quack[0]++;
        } else {
            if (!quack[t - 1]--) {      // no current duck was expecting this character
                goto bad;
            }
            if (t == 4) { // 'k'
                n_quacks--;             // the quackination sequence has been finished 
            } else {
                quack[t]++;
            }
        }
    }

    if (n_quacks) { // unfinished quack remaining
    bad:
        cout << -1 << '\n';
    } else {
        cout << n_ducks << '\n';
    }
}