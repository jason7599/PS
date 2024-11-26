#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4'000;

int n, nn, arr[4][MAX];
int ab[MAX * MAX], cd[MAX * MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    nn = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[j][i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab[i * n + j] = arr[0][i] + arr[1][j];
            cd[i * n + j] = arr[2][i] + arr[3][j];
        }
    }

    sort(ab, ab + nn);
    sort(cd, cd + nn);

    int l = 0;
    int r = nn - 1;
    int64_t ans = 0;

    while (l < nn && r >= 0)
    {
        int l_val = ab[l];
        int r_val = cd[r];
        int sum = l_val + r_val;

        if (sum == 0)
        {
            int l_cnt = 1;
            int r_cnt = 1;

            while (++l < nn
            && ab[l] == l_val)
                l_cnt++;
            
            while (--r >= 0
            && cd[r] == r_val)
                r_cnt++;

            ans += (int64_t) l_cnt * r_cnt;
        }
        else if (sum < 0)
            l++;
        else
            r--;


    }

    cout << ans;

    return 0;
}