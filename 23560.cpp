#include <iostream>

using namespace std;

int solve(int num_medicine, short front, short next)
{
    static int dp[46][3][3];

    if (num_medicine == 1)
        return front % 2 == next % 2;

    if (dp[num_medicine][front][next])
        return dp[num_medicine][front][next];

    int res = 0;
    // take front
    if (front % 2 == next % 2)
        res = solve(num_medicine - 1, (front + 1) % 3, (next + 1) % 3);
    // take back
    if (((front + num_medicine - 1) % 3) % 2 == next % 2)
        res += solve(num_medicine - 1, front, (next + 1) % 3);

    return dp[num_medicine][front][next] = res;
}

int main()
{
    int days;
    cin >> days;
    cout << solve(days * 3, 0, 0);
    return 0;
}