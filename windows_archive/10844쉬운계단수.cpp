#include <iostream>

using namespace std;

int n, dp[101][101], mod = 1'000'000'000;
bool contains[10];

int func(int start, int len, int numbersLeft = 10) {

    if (dp[start][len]) return dp[start][len];

    if (len == 1) {
        if (numbersLeft == 1 && !contains[start]) {
            dp[start][len] = 1;
            return 1;
        }
        return 0;
    }

    bool flag = !contains[start];
    if (flag) {
        contains[start] = true;
        numbersLeft--;
    }

    int res = 0;
    if (start != 9) res = func(start + 1, len - 1, numbersLeft);
    if (start) res += func(start - 1, len - 1, numbersLeft);

    if (flag) contains[start] = false;

    return dp[start][len] = res % mod;

}

int main() {

    cin >> n;

    int res = 0;
    for (int i = 1; i < 10; i++)
        res += func(i, n);
    cout << res % mod;

}