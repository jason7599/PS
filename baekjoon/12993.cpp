#include <bits/stdc++.h>
using namespace std;

// 3진수로 표현했을 때 0과 1만 존재하는지 확인
bool chk1(int v) {
    int d = 1;
    for (; d * 3 <= v; d *= 3);
    for (; v; d /= 3) {
        if (v < d) {
            continue;
        }
        if (v / d > 1) {
            return 0;
        }
        v -= d;
    }
    return 1;
}

// 3진수로 표현했을 때 1만 존재하는지 확인
bool chk2(int v) {
    for (int d = 1; v > 0; d *= 3) {
        v -= d;
    }
    return !v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    cout << (chk1(x) && chk1(y) && chk2(x + y)) << '\n';
}