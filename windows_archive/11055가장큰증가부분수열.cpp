#include <iostream>

using namespace std;

int length, arr[1000], dp[1000], ans;

int main() {

    cin >> length;

    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];

    for (int i = 0; i < length; i++) {
        int maxSum = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (maxSum < dp[j])
                    maxSum = dp[j];
            }
        }
        if ((dp[i] = arr[i] + maxSum) > ans)
            ans = dp[i];
    }

    cout << ans;

}