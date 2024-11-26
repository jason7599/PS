#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[2000];

bool fuck(int i)
{
    int x = arr[i]; // 만들고 싶은 값

    int l = i == 0 ? 1 : 0;
    int r = i == n - 1 ? n - 2 : n - 1;

    while (l < r)
    {
        int v = arr[l] + arr[r];

        if (v == x)
            return true;
        
        if (v < x)
            l++;
        else
            r--;

        if (l == i)
            l++;
        if (r == i)
            r--;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (fuck(i))
            ans++;
    }

    cout << ans;

    return 0;
}