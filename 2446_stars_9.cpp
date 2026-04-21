#include <bits/stdc++.h>

using namespace std;

string f(int n, int i)
{
    return string(i, ' ') + string(2 * n - 1 - 2 * i, '*') + '\n';
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        cout << f(n, n - 1 - abs(n - 1 - i));
    }
}