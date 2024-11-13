#include <iostream>
#include <algorithm>

using namespace std;

int a_len, b_len;
int A[(int)1e6];
int B[(int)1e6];

int b_search(int val)
{
    int l = 0;
    int r = b_len - 1;
    int ans_i = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        
        if (B[mid] == val)
        {
            ans_i = mid;
            break;
        }

        if (abs(val - B[ans_i]) > abs(val - B[mid])
        || (abs(val - B[ans_i]) == abs(val - B[mid]) && B[mid] < B[ans_i]))
            ans_i = mid;
        
        if (B[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return B[ans_i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> a_len >> b_len;
        for (int i = 0; i < a_len; i++)
            cin >> A[i];
        for (int i = 0; i < b_len; i++)
            cin >> B[i];
        
        sort(B, B + b_len);

        int ans = 0;
        for (int i = 0; i < a_len; i++)
            ans += b_search(A[i]);
        cout << ans << '\n';
    }

    return 0;
}