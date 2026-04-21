#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, s;
    cin >> n >> s;

    int x;
    cin >> x;
    
    int gcd = abs(x - s);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        gcd = __gcd(gcd, abs(x - s));
    }

    cout << gcd;
    return 0;
}