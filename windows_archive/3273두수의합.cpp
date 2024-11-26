#include <iostream>
#include <algorithm>

using namespace std;

int arr[100'000];

int main()
{
    int len;
    cin >> len;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    sort(arr, arr + len);

    int target;
    cin >> target;

    int ans = 0;
    int l = 0;
    int r = len - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == target)
        {
            ans++;
            l++;
            r--;
        }
        else if (arr[l] + arr[r] < target)
            l++;
        else
            r--;
    }

    cout << ans;
    return 0;
}