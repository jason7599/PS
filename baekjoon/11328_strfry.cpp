#include <bits/stdc++.h>

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
        
        int alph_cnt[26] = {};

        if (lhs.length() != rhs.length())
            goto bad;

        for (char c : lhs)
            !alph_cnt[c - 'a']++;

        for (char c : rhs)
        {
            if (--alph_cnt[c - 'a'] < 0)
                goto bad;
        }

        std::cout << "Possible\n";
        continue;
bad:
        std::cout << "Impossible\n";
    }
}