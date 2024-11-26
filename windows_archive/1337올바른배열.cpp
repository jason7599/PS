#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, arr[50];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);

    int ans = 4;

    int r = 1;
    int req = 4;

    for (int l = 0; l < n; l++)
    {
        while (r < n && arr[r] <= arr[l] + 4)
        {
            r++;
            req--;
        }

        ans = min(ans, req);

        req++;
    }

    cout << ans;
    return 0;
}