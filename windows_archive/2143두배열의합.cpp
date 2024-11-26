#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1001], B[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    int n, m;
    int sum = 0;

    cin >> t;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        A[i] = sum;
    }

    vector<int> A_sum;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            A_sum.push_back(A[i] - A[j]);
    }

    sort(A_sum.begin(), A_sum.end());

    sum = 0;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        sum += x;
        B[i] = sum;
    }

    vector<int> B_sum;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < i; j++)
            B_sum.push_back(B[i] - B[j]);
    }

    sort(B_sum.begin(), B_sum.end());

    // cout << "A_sum: ";
    // for (int i : A_sum)
    //     cout << i << ", ";
    // cout << "\nB_sum: ";
    // for (int i : B_sum)
    //     cout << i << ", ";
    // cout << '\n';

    int l = 0;
    int r = B_sum.size() - 1;
    int64_t ans = 0;

    while (l < A_sum.size() && r >= 0)
    {
        int l_val = A_sum[l];
        int r_val = B_sum[r];
        int sum = l_val + r_val;

        if (sum == t)
        {
            int l_cnt = 1;
            int r_cnt = 1;

            while (++l < A_sum.size() && A_sum[l] == l_val)
                l_cnt++;
            
            while (--r >= 0 && B_sum[r] == r_val)
                r_cnt++;

            ans += (int64_t) l_cnt * r_cnt;
        }
        else if (sum < t)
            l++;
        else
            r--;
    }

    cout << ans;

    return 0;
}