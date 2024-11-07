#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 987654321;

int solve(int len, int start)
{
    static int dp[100'001][10]; // dp[len][x]: # of strings with length len that starts with x

    if (len == 1)
        return 1;

    if (dp[len][start])
        return dp[len][start];
    
    int res = 0;
    for (int next = max(start - 2, 1); next <= min(start + 2, 9); next++)
        res = (res + solve(len - 1, next)) % mod;

    return dp[len][start] = res;            
}

int main()
{
    int len;
    cin >> len;
    
    int ans = 0;
    for (int i = 1; i <= 9; i++)
        ans = (ans + solve(len, i)) % mod;
    
    cout << ans;
    return 0;
}