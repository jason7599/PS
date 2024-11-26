#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k, n[1023], i, j;

    cin >> k;

    for (i = 0; i < (1 << k) - 1; i++)
    {
        cin >> n[i];
    }
    
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < (1 << i); j++)
        {
            cout << n[(1 << (k - i - 1)) - 1 + j * (1 << (k - i))] << ' ';
        }
        cout << '\n';
    }
}