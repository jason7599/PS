#include <iostream>
#include <algorithm>
#include <set>
#include <map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_codes;
    std::cin >> num_codes;

    std::map<char, bool> f_cnt;
    std::set<std::pair<char, char>> codes;

    while (num_codes--)
    {
        char f, s;
        std::cin >> f >> s;

        if (f_cnt.find(f) == f_cnt.end())
            f_cnt[f] = 0;
        else
            f_cnt[f] = 1;

        codes.insert({f, s});
    }

    std::set<char> res;

    for (const auto& [f, dup] : f_cnt)
    {
        for (const auto& [f1, s] : codes)
        {
            if (dup || f != f1)
                res.insert(std::max(f, s));
        }
    }

    std::cout << res.size() << '\n';
    for (char c : res)
        std::cout << c << ' ';
}