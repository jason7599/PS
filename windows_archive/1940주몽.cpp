#include <iostream>

using namespace std;

bool yes[100'001];
int arr[15'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        yes[x] = true;
        arr[i] = x;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x * 2 != m && yes[m - x])
        {
            ans++;
            yes[x] = false;
        }
    }

    cout << ans;
 
    return 0;
}