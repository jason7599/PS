#include <iostream>
#include <algorithm>

using namespace std;

int solve(int x)
{
    int ans = 0;
    for (int d = 9; d > 1; d--)
    {
        while (x % d == 0)
        {
            x /= d;
            ans++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << solve(x) << '\n';
    }
    return 0;
}