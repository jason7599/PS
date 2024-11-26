#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int ans = 0;
    for (int i = 0; i <= 6; i++)
    {
        if ((x >> i) & 1)
            ans++;
    }

    cout << ans;
}