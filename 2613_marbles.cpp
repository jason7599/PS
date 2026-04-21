#include <iostream>
#include <algorithm>
#include <vector>

int n_marbles, marbles[300], n_groups;

std::vector<int> deconstruct(int max_sum)
{
    std::vector<int> res;

    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n_marbles; i++)
    {
        if (sum + marbles[i] > max_sum)
        {
            res.push_back(cnt);
            cnt = 1;
            sum = marbles[i];       
        }
        else
        {
            sum += marbles[i];
            cnt++;
        }
    }
    res.push_back(cnt);

   // invariants:
    // all the sums of cnts in res is <= max_sum.
    // so we can safely split them in to lesser parts.
    size_t idx = res.size() - 1;
    while (res.size() < n_groups)
    {
        if (res[idx] > 1)
        {
            res[idx]--;
            res.push_back(1);
        }
        else
            idx--;
    }
    
    return res;   
}

bool check(int max_sum)
{
    int sum = 0;
    int group_cnt = 1;
    for (int i = 0; i < n_marbles; i++)
    {
        if (sum + marbles[i] > max_sum)
        {
            if (marbles[i] > max_sum || ++group_cnt > n_groups)
                return 0;

            sum = marbles[i];
        }
        else
            sum += marbles[i];
    }
    return 1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_marbles >> n_groups;

    int low = 0;
    int high = 0;

    for (int i = 0; i < n_marbles; i++)
    {
        int x;
        std::cin >> x;

        low = std::max(low, x);
        high += x;

        marbles[i] = x;
    }

    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (check(mid))
            high = mid; // high is kept valid
        else
            low = mid + 1;
    }

    std::cout << high << '\n';

    auto vec = deconstruct(high);
    for (int i : vec)
        std::cout << i << ' ';
    std::cout << '\n';
}