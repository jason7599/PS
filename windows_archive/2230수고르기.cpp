#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    static int arr[100'000];
    int arr_len, target_diff;

    cin >> arr_len >> target_diff;
    for (int i = 0; i < arr_len; i++)
        cin >> arr[i];

    sort(arr, arr + arr_len);

    int left = 0, right = 0;
    int ans_diff = arr[arr_len - 1] - arr[0];

    while (right < arr_len) // TODO
    {
        int diff = arr[right] - arr[left];

        if (diff == target_diff)
        {
            ans_diff = diff;
            break;
        }

        if (diff < target_diff)
        {
            right++;
        }
        else // diff > target_diff
        {
            if (diff < ans_diff)
            {
                ans_diff = diff;
            }
            left++;
        }
    }
    
    cout << ans_diff;

    return 0;
}