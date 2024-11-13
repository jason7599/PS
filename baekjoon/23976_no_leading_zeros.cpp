#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int solve(const string& str, int index, int splices)
{
    static int memo[2500][2500];

    if (!splices)
    {
        if (index + 1 < str.length() && str[index] == '0')
            return 0;
        return 1;
    }

    if (memo[index][splices])
        return max(0, memo[index][splices]);

    int res = 0;
    if (str[index] == '0')
    {
        if (str[index] + 1 == '0')
            res = 0;
        else
            res = solve(str, index + 1, splices - 1);
    }
    else
    {
        for (int i = index; i < str.length() - splices; i++)
        {
            res += solve(str, i + 1, splices - 1);
            res %= mod;
        }
    }

    if (!res)
    {
        memo[index][splices] = -1;
        return 0;
    }

    return memo[index][splices] = res;
}

int main()
{
    int len, k;
    cin >> len >> k;

    string str;
    cin >> str;

    cout << solve(str, 0, k - 1);

    return 0;
}