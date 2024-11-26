#include <iostream>
#include <algorithm>

using namespace std;

int arr[100'000];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] * (n - i);
        if (ans < x)
            ans = x;
    }

    cout << ans;

    return 0;
}