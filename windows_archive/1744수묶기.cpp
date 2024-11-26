#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, arr[50]; 
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int r = n - 1, ans = 0;

    while (r > -1)
    {
        if (r == 0)
        {
            ans += arr[0];
            break;
        }

        int x = arr[r];
        int y = arr[r - 1];

        if (x * y >= x + y) // 묶기
        {
            ans += x * y;
            r -= 2;
        }
        else
        {
            ans += x;
            r -= 1;
        }
    }

    cout << ans;

    return 0;
}