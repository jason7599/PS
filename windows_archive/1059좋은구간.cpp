#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[50];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int len;
    cin >> len;

    vector<int> arr(len);

    for (int i = 0; i < len; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    
    int n;
    cin >> n;

    /**
     * a < n < b
     */

    int bi = lower_bound(arr.begin(), arr.end(), n) - arr.begin();
    int b = arr[bi];
    if (b == n)
    {
        cout << 0;
        return 0;
    }

    int a = bi ? arr[bi - 1] : 0;

    cout << b - a - 2 + (n - 1 - a) * (b - n - 1);

    return 0;
}