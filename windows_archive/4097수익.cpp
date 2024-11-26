#include <iostream>
#include <algorithm>

using namespace std;

int arr[250'000];
int dp[250'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        int len;
        cin >> len;

        if (len == 0)
            break;

        for (int i = 0; i < len; i++)
            cin >> arr[i];

        int ans = dp[0] = arr[0];
        for (int i = 1; i < len; i++)
            ans = max(ans, dp[i] = max(dp[i - 1] + arr[i], arr[i]));

        cout << ans << '\n';
    }

    return 0;
}