#include <iostream>

using namespace std;

int solve(int a, int b)
{
    int ans = 0;

    while (a > b)
    {
        if (a % 2)
        {
            a++;
            ans++;
        }
        a /= 2;
        ans++;
    }

    ans += b - a;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}