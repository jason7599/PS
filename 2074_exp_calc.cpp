#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

int solve(int target_exp)
{
    std::set<std::pair<int, int>> v;
    std::queue<std::pair<int, int>> q;

    q.push({0, 1});
    v.insert({0, 1});

    int ops = 0;
    int q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int e0 = q.front().first;
            int e1 = q.front().second;
            q.pop();

            if (e0 == target_exp || e1 == target_exp)
                return ops;
            
            std::set<std::pair<int, int>> next_ops
            {
                {e0, e0 + e1},
                {e0 + e1, e1},
                {e0 + e0, e0},
                {e0 + e0, e1},
                {e1 + e1, e0},
                {e1 + e1, e1},
                {e0, 0},
                {e1, 0},
                {e0, std::abs(e0 - e1)},
                {std::abs(e0 - e1), e1}
            };

            for (auto [n0, n1] : next_ops)
            {
                std::pair<int, int> next
                    = {std::min(n0, n1), std::max(n0, n1)};
                
                if (v.find(next) == v.end())
                {
                    v.insert(next);
                    q.push(next);
                }
            }
        }
        ops++;
    }
    return -1;
}

int main()
{
    int exp;
    std::cin >> exp;
    std::cout << solve(exp);
}