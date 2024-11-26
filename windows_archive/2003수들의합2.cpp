#include <iostream>

using namespace std;

int arr[10'001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int ans = 0;
    int l = 0;
    int r = 1;
    while (r <= n)
    {
        int64_t sum = arr[r] - arr[l];
        if (sum == m)
        {
            ans++;
            r++;
            l++;
        }
        else if (sum > m)
            l++;
        else
            r++;
    }

    cout << ans;
    return 0;
}