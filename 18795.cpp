#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    long long ans = 0;
    for (int i = 0; i < n + m; i++)
    {
        int v;
        cin >> v;
        ans += v;
    }
    cout << ans;
    return 0;
}