#include <iostream>
#include <algorithm>

const int mod = 1e6;

const int d_attended = 0;
const int d_late = 1;
const int d_absent = 2;

int solve(int days_left, bool late, int absent)
{
    static int memo[1001][2][3];

    if (!days_left)
        return 1;

    if (memo[days_left][late][absent])
        return std::max(memo[days_left][late][absent], 0);

    int res = solve(days_left - 1, late, 0);

    if (!late)
        res = (res + solve(days_left - 1, 1, 0)) % mod;
    
    if (absent < 2)
        res = (res + solve(days_left - 1, late, absent + 1)) % mod;
    
    memo[days_left][late][absent] = res ? res : -1;
    return res;
}

int main()
{
    int days;
    std::cin >> days;
    std::cout << solve(days, 0, 0);
}