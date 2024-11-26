#include <iostream>

using namespace std;

typedef long long ll;

int len_entire, nums[98], target;

ll solve(int val, int index = 0)
{
    static ll memo[21][98];

    if (index == len_entire - 2)
    {
        if (val == target)
            return 1;
        return 0;
    }

    if (memo[val][index] == -1)
        return 0;
    if (memo[val][index])
        return memo[val][index];

    ll res = 0;
    int num = nums[index];
    if (val + num <= 20)
        res = solve(val + num, index + 1);
    if (val - num >= 0)
        res += solve(val - num, index + 1);

    if (res == 0)
    {
        memo[val][index] = -1;
        return 0;
    }

    return memo[val][index] = res;
}

int main()
{
    int leading;

    cin >> len_entire;
    cin >> leading;
    for (int i = 0; i < len_entire - 2; i++)
        cin >> nums[i];
    cin >> target;

    cout << solve(leading);
}