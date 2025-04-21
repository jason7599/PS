#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (string line; getline(cin, line);) {
        if (line == "END") break;

        for (int i = line.length() - 1; i >= 0; i--) {
            cout << line[i];
        }
        cout << '\n';
    }
}