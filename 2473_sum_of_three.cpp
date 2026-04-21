#include <iostream>
#include <algorithm>

int elems[5000];

int main()
{
    int num_elems;
    std::cin >> num_elems;
    for (int i = 0; i < num_elems; i++)
        std::cin >> elems[i];
    
    std::sort(elems, elems + num_elems);

    long long min_diff = 3e9;
    int ans[3];

    for (int i = 0; i < num_elems; i++)
    {
        int l = 0;
        int r = num_elems - 1;
        while (l < r)
        {
            if (l == i)
            {
                l++;
                continue;
            }
            if (r == i)
            {
                r--;
                continue;
            }

            long long sum = elems[l] + elems[r];
            long long diff = elems[i] + sum < 0 ? -elems[i] - sum : elems[i] + sum;

            if (diff < min_diff)
            {
                ans[0] = elems[i];
                ans[1] = elems[l];
                ans[2] = elems[r];
                min_diff = diff;
                if (!min_diff)
                    break;
            }
            
            if (sum + elems[i] > 0)
                r--;
            else
                l++;
        }

        if (!min_diff)
            break;
    }

    std::sort(ans, ans + 3);
    for (int i = 0; i < 3; i++)
        std::cout << ans[i] << ' ';
}