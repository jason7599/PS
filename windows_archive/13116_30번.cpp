#include <iostream>

using namespace std;

int solve(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a /= 2;
        else
            b /= 2;
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) * 10 << '\n';
    }
    return 0;
}