#include <iostream>
#include <string>

int main()
{
    int len;
    std::cin >> len;

    std::string str;
    std::cin >> str;

    int num_missing = 0;
    for (char c : str)
    {
        if (c == 'G')
            num_missing++;
    }

    for (int comb = 0; comb < 1 << num_missing; comb++)
    {
        int l_cnt = 0;
        int t_idx = 0;
        bool good = 1;
        for (char c : str)
        {
            bool is_l;
            if (c == 'G')
                is_l = (comb >> t_idx++) & 1;
            else
                is_l = c == '(';
            
            if (is_l)
                l_cnt++;
            else
            {
                if (!l_cnt--)
                {
                    good = 0;
                    break;
                }
            }
        }

        good &= !l_cnt;

        if (good)
        {
            t_idx = 0;
            for (char c : str)
            {
                if (c == 'G')
                {
                    if ((comb >> t_idx++) & 1)
                        std::cout << '(';
                    else
                        std::cout << ')';
                }
                else
                    std::cout << c;
            }

            break;
        }
    }
}