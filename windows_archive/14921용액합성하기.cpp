#include <iostream>
#include <algorithm>

using namespace std;

int arr[100'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0;
    int r = n - 1;
    int best = arr[r] + arr[l];

    while (l < r)
    {
        int sum = arr[r] + arr[l];

        if (sum == 0)
        {
            cout << 0;
            return 0;    
        }
        
        if (abs(sum) < abs(best))
            best = sum;
        
        if (sum > 0)
            r--;
        else
            l++;
    }

    cout << best;

    return 0;
}