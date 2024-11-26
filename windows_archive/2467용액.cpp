#include <iostream>
#include <algorithm>

using namespace std;

int arr_len;
int arr[100'000];

void solve()
{
    int l = 0;
    int r = arr_len - 1;

    int min_diff = 2e9 + 1;
    int ans_l;
    int ans_r;

    while (l < r)
    {
        int sum = arr[l] + arr[r];
        int diff = abs(sum);

        if (diff < min_diff)
        {
            ans_l = l;
            ans_r = r;
            min_diff = diff;
        }

        if (sum > 0)
            r--;
        else if (sum < 0)
            l++;
        else
            break;
    }

    cout << arr[ans_l] << ' ' << arr[ans_r];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> arr_len;
    for (int i = 0; i < arr_len; i++)
        cin >> arr[i];

    solve();
    return 0;
}