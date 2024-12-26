#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    for (int tc = 1; tc <= n_tc; tc++)
    {
        std::string ans, input;
        std::cin >> ans >> input;

        int n_deletes = 0;
        size_t ans_idx = 0;
        for (char c : input)
        {
            if (ans_idx == ans.length() || c != ans[ans_idx])
                n_deletes++;
            else
                ans_idx++;
        }

        std::cout << "Case #" << tc << ": ";
        if (ans_idx == ans.length())
            std::cout << n_deletes;
        else
            std::cout << "IMPOSSIBLE";
        std::cout << '\n';
    }
}