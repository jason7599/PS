#include <bits/stdc++.h>
using namespace std;

bool chk(int x, int y) {
    if (!x && !y) {
        return 1;
    }
    int d = 1;
    for (; d * 3 <= x || d * 3 <= y; d *= 3);
    for (; d; d /= 3) {
        if (x >= y) {
            x -= d;
            if (x < 0) {
                return 0;
            }
        } else {
            y -= d;
            if (y < 0) {
                return 0;
            }
        }
    }
    return !x && !y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    cout << chk(x, y) << '\n';
}