#include <iostream>

using namespace std;

using ll = long long int;

ll fuck(int s, int k)
{
    static ll dp[101][21];

    if (!k)
        return 1;

    if (dp[s][k])
        return dp[s][k];

    ll ans = 0;
    for (int i = 1; i <= s - k + 1; i++)
    {
        ll temp = i * fuck(s - i, k - 1);
        if (temp > ans)
            ans = temp;
    }
    
    return dp[s][k] = ans;
}

int main()
{
    int s, k;
    cin >> s >> k;

    cout << fuck(s, k);

    return 0;
}