#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int t = a + b;

    int res = 0;
    int ones = t <= n ? t : 2 * n - t;

    for (int i = 0; i < ones; i++)
        res |= 1 << (n - 1 - i);
    
    cout << res;

    return 0;
}