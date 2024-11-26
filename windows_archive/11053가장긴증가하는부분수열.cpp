#include <iostream>

using namespace std;

// a: 수열
// dp[n]: 원소 n을 마지막으로 하는 수열의 가장 긴 증가하는 부분수열의 길이

int n, a[1000], dp[1000], ans;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                if (max < dp[j])
                    max = dp[j];
        }

        if ((dp[i] = ++max) > ans) ans = dp[i];
    }

    cout << ans;

}