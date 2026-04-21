#include <bits/stdc++.h>

bool check(const std::string& lhs, const std::string& rhs)
{       
    if (lhs.length() != rhs.length())
        return 0;

    int alph_cnt[26] = {};

    for (char c : lhs)
        !alph_cnt[c - 'a']++;

    for (char c : rhs)
    {
        if (--alph_cnt[c - 'a'] < 0)
            return 0;
    }

    return 1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    while (n_tc--)
    {
        std::string lhs, rhs;
        std::cin >> lhs >> rhs;
        std::cout << (check(lhs, rhs) ? "Possible" : "Impossible") << '\n';
    }
}