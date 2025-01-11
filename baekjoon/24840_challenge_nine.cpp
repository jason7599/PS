#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    for (int tc = 1; tc <= n_tc; tc++)
    {
        std::string num_str;
        std::cin >> num_str;

        int mod_nine = 0;
        for (char c : num_str)
        {
            mod_nine += c - '0';
            mod_nine %= 9;
        }

        if (!mod_nine)
        {
            num_str.insert(1, 1, '0');
        }
        else
        {
            int add_num = 9 - mod_nine;

            size_t ins_pos;
            for (ins_pos = 0;
                ins_pos < num_str.length() 
                    && add_num >= num_str[ins_pos] - '0';
                ins_pos++);

            num_str.insert(ins_pos, 1, (char)add_num + '0');
        }

        std::cout << "Case #" << tc << ": " << num_str << '\n';
    }
}