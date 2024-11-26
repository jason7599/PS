#include <iostream>

using namespace std;

const int MAX = 1'000'000'009;

int64_t dp[1'000'001];

int64_t fuck(int x)
{
    if (dp[x])
        return dp[x];

    return dp[x] = (fuck(x - 1) + fuck(x - 2) + fuck(x - 3)) % MAX;
}

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        cout << fuck(x) << '\n';
    }
}