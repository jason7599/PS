#include <iostream>
#include <algorithm>

using namespace std;

int arr[100'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; 
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i]; 

    sort(arr, arr + n);

    int l = 0;
    int r = n - 1;

    int best_val = 2'000'000'000;
    int best_l;
    int best_r;

    while (l < r)
    {
        int sum = arr[l] + arr[r];
        int val = abs(sum);

        if (val < best_val)
        {
            best_val = val;
            best_l = l;
            best_r = r;

            if (val == 0)
                break;
        }

        if (sum < 0)
            l++;
        else
            r--;
    }

    cout << arr[best_l] << ' ' << arr[best_r];

    return 0;
}