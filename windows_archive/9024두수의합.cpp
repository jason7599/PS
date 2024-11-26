#include <iostream>
#include <algorithm>

using namespace std;

int arr_len, arr[1'000'000];

int fuck(int target)
{
    sort(arr, arr + arr_len);

    int l = 0;
    int r = arr_len - 1;
    int min_diff = 2e8 + 1;
    int count;

    while (l < r)
    {
        int sum = arr[l] + arr[r];
        int diff = abs(target - sum);

        if (diff < min_diff)
        {
            min_diff = diff;
            count = 1;
        }
        else if (diff == min_diff)
            count++;
        
        if (sum > target)
            r--;
        else if (sum < target)
            l++;
        else
            l++, r--;
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int target;
        cin >> arr_len >> target;
        for (int i = 0; i < arr_len; i++)
            cin >> arr[i];
        cout << fuck(target) << '\n';
    }
    return 0;
}