#include <iostream>

using namespace std;

void solve(int n)
{
    if (n % 4 < 2)
        cout << n << '\n';
    else
        cout << n - 1 << '\n';
    
    int num_ones = n / 2;
    for (int last = n - 1; last > 1; last -= 2)
        cout << last << ' ' << last - 1 << '\n';

    int num_zeros = 0;
    while (num_ones > 1)
    {
        cout << "1 1\n";
        num_ones -= 2;
        num_zeros++;
    }

    while (num_zeros > 1)
    {
        cout << "0 0\n";
        num_zeros--;
    }

    if (num_ones)
    {
        if (num_zeros)
            cout << "0 1\n";
        cout << "1 " << n << '\n';
    }
    else if (num_zeros)
        cout << "0 " << n << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    solve(n);

    return 0;
}