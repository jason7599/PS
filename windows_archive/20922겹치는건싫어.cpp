#include <iostream>
#include <algorithm>

using namespace std;

int arr[200'000];
int cnt[100'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int arr_len, max_dup;
    cin >> arr_len >> max_dup;

    for (int i = 0; i < arr_len; i++)
        cin >> arr[i];
    
    int l = 0;
    int r = 0;
    int ans = 0;
    while (r < arr_len)
    {
        while (r < arr_len && cnt[arr[r]] + 1 <= max_dup)
            cnt[arr[r++]]++;
        
        ans = max(ans, r - l);

        cnt[arr[l++]]--;
    }

    cout << ans;
    return 0;
}