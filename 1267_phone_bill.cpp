#include <bits/stdc++.h>

using namespace std;

int M(int t)
{
    return (t / 60 + 1) * 15;
}

int Y(int t)
{
    return (t / 30 + 1) * 10;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int m = 0, y = 0;
    while (N--)
    {
        int t;
        cin >> t;
        m += M(t);
        y += Y(t);
    }

    int mn = min(m, y);

    if (y == mn)
        cout << "Y ";
    if (m == mn)
        cout << "M ";
    cout << mn << '\n';
}