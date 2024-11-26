#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        int _i = i;
        while (_i % 5 == 0)
        {
            _i /= 5;
            ans++;
        }
    }
    cout << ans;
}