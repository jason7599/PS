#include <bits/stdc++.h>

class Solution
{
private:
    int64_t target;
    int64_t closest_val = -1;
    std::string ans = "-1";
    std::string val;
    std::array<bool, 10> used{};

    bool dfs(int len)
    {
        if (!len)
        {
            int64_t t = std::stoll(val);

            if (std::abs(target - t) < std::abs(target - closest_val))
            {
                closest_val = t;
                ans = val;
            }

            return t >= target;
        }

        for (int num = 0; num < 10; num++)
        {
            if (!used[num])
            {
                used[num] = 1;
                val.push_back((char)(num + '0'));

                if (dfs(len - 1))
                    return 1;

                val.pop_back();
                used[num] = 0;
            }
        }

        return 0;
    }

public:
    Solution(int64_t t)
        : target(t) {}

    std::string solve()
    {
        if (target >= 9876543210)
            return "9876543210";

        for (int len = 1; len <= 10; len++)
        {
            if (dfs(len))
                break;
        }

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int64_t target;
    std::cin >> target;

    Solution sol(target);
    std::cout << sol.solve();
}