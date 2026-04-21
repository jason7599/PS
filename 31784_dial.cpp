#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len, n_turns;
    cin >> len >> n_turns;

    string dials;
    cin >> dials;

    for (char& c : dials) {
        if (c == 'A') {
            continue;
        }
        if ('Z' - c + 1 <= n_turns) {
            n_turns -= 'Z' - c + 1;
            c = 'A';
            if (!n_turns) {
                break;
            }
        }
    }

    int t = dials.back() - 'A';
    t = (t + n_turns % 26) % 26;

    dials.back() = t + 'A';

    cout << dials << '\n';
}