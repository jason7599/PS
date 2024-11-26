#include <iostream>
#include <cmath>

using namespace std;

int upperBound, opCount, maxNum;

void func(int opIndex = 0, int lastOp = 2, int res = 1) {

    if (res >= upperBound) return;

    if (opIndex == opCount) {
        if (res > maxNum)
            maxNum = res;
        return;
    }

    for (int i = lastOp; i < 10; i++)
        func(opIndex + 1, i, res * i);

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int maxDigits;
    cin >> maxDigits >> opCount;

    upperBound = pow(10, maxDigits);

    func();

    if (!maxNum) cout << -1;
    else cout << maxNum;

}