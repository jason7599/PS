#include <iostream>
#include <algorithm>

int arr[(int)1e6];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int len;
    std::cin >> len;

    for (int i = 0; i < len; i++)
        std::cin >> arr[i];
    
    std::sort(arr, arr + len);

    int target;
    std::cin >> target;

    int min_diff = 3e4 + 1;
    u_int64_t min_diff_cnt;

    int l = 0;
    int r = len - 1;

    while (l < r)
    {
        int lval = arr[l];
        int rval = arr[r];

        u_int64_t cnt;

        if (lval == rval)
        {
            cnt = (r - l + 1) * (r - l) / 2;
            l = r; // end
        }
        else
        {
            int lcnt = 1;
            int rcnt = 1;

            while (arr[l + 1] == lval)
            {
                lcnt++;
                l++;
            }

            while (arr[r - 1] == rval)
            {
                rcnt++;
                r--;
            }

            cnt = (u_int64_t)lcnt * rcnt;
        }

        int sum = lval + rval;
        int diff = std::abs(target - sum);

        if (diff < min_diff)
        {
            min_diff = diff;
            min_diff_cnt = cnt;
        }
        else if (diff == min_diff)
            min_diff_cnt += cnt;
        
        if (sum < target)
            l++;
        else if (sum > target)
            r--;
        else
            l++, r--;
    }

    std::cout << min_diff_cnt;
}