#include <iostream>
#include <algorithm>

using namespace std;

int dp[100'001];

int func(int n) {
    if (!n || dp[n]) return dp[n];
    int res = func(n - 1);
    for (int i = 2; i * i <= n; i++) 
        res = min(res, func(n - i * i));
    return dp[n] = 1 + res;
}

int main() {

    int n; cin >> n;
    cout << func(n);

}