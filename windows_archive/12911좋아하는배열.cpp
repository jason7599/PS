#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int solve(int arr_len, const int max_val, int prev_val = -1)
{
    static int dp[10][100'001]; // dp[n][x]: prev_val = x인 길이 n짜리 좋은 배열의 수
    static int saved;

    if (!arr_len)
        return 1;

    if (prev_val != -1)
    {
        if (dp[arr_len][prev_val])
        {
            cout << "saved op for (" << arr_len << ", " << prev_val << "): " << ++saved << '\n';
            return max(dp[arr_len][prev_val], 0);
        }
    }

    int res = 0;
    for (int val = 1; val <= max_val; val++)
    {
        if (prev_val == -1
        || prev_val <= val || prev_val % val)
            res = (res + solve(arr_len - 1, max_val, val)) % mod;
    }

    if (prev_val != -1)
    {
        if (res)
            return dp[arr_len][prev_val] = res;
        
        dp[arr_len][prev_val] = -1;
        return 0;
    }

    return res;
}

int main()
{
    int arr_len, max_val;
    cin >> arr_len >> max_val;
    cout << solve(arr_len, max_val);
    return 0;
}