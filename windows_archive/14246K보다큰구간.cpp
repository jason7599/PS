#include <iostream>

using namespace std;

long long arr[100'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int arr_len, k;
    cin >> arr_len;

    for (int i = 1; i <= arr_len; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    cin >> k;

    long long ans = 0;
    int r = 1;
    for (int l = 0; l < arr_len; l++)
    {
        while (r <= arr_len && arr[r] - arr[l] <= k)
            r++;
        
        ans += arr_len - r + 1;

        if (r > arr_len)
            break;
    }

    cout << ans;

    return 0;
}