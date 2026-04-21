#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_ops;
    std::cin >> n_ops;

    std::unordered_map<int, int> vals_cnt;

    int homo_cnt = 0; // # of values that appear at least twice
    int n_unique = 0;

    while (n_ops--)
    {
        std::string op;
        int val;

        std::cin >> op >> val;

        if (op == "insert")
        {
            if (!vals_cnt[val]++)
                n_unique++;
            else if (vals_cnt[val] == 2)
                homo_cnt++;
        }
        else // delete
        {
            if (vals_cnt.count(val) && vals_cnt[val])
            {
                if (vals_cnt[val]-- == 2)
                    homo_cnt--;
                else if (!vals_cnt[val])
                    n_unique--;
            }
        }

        bool is_homo = homo_cnt;
        bool is_hetero = n_unique > 1;

        if (is_homo && is_hetero)
            std::cout << "both";
        else if (is_homo)
            std::cout << "homo";
        else if (is_hetero)
            std::cout << "hetero";
        else
            std::cout << "neither";
        std::cout << '\n';
    }
}