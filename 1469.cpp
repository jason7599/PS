#include <bits/stdc++.h>

bool solve(const std::vector<int>& elems, std::vector<int>& res, size_t idx = 0, int used_mask = 0)
{
    if (used_mask == (1 << elems.size()) - 1)
        return 1;
    
    if (idx == res.size())
        return 0;
    
    if (res[idx] != -1)
        return solve(elems, res, idx + 1, used_mask);
    
    for (int i = 0; i < elems.size(); i++)
    {
        if (!(used_mask & (1 << i)))
        {
            if (idx + elems[i] + 1 < res.size() && res[idx + elems[i] + 1] == -1)
            {
                res[idx] = res[idx + elems[i] + 1] = elems[i];
                if (solve(elems, res, idx + 1, used_mask | (1 << i)))
                    return 1;
                res[idx + elems[i] + 1] = -1;
            }
        }
    }

    res[idx] = -1;
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_elems;
    std::cin >> n_elems;

    std::vector<int> elems(n_elems);
    for (int& elem : elems)
        std::cin >> elem;

    std::sort(elems.begin(), elems.end());
    
    std::vector<int> res(n_elems * 2, -1);

    if (solve(elems, res))
    {
        for (int i : res)
            std::cout << i << ' ';
    }
    else
        std::cout << -1;

    std::cout << '\n';
}