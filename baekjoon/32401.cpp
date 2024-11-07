#include <iostream>

char str[100];

bool check(int start, int len)
{
    if (str[start] != 'A' || str[start + len - 1] != 'A')
        return 0;

    bool n_cnt = 0;
    for (int i = start + 1; i < start + len - 1; i++)
    {
        if (str[i] == 'A')
            return 0;

        if (str[i] == 'N')
        {
            if (n_cnt)
                return 0;
            n_cnt = 1;
        }
    }
    
    return n_cnt;
}

int main()
{
    int str_len;
    std::cin >> str_len;
    for (int i = 0; i < str_len; i++)
        std::cin >> str[i];
    
    int ans = 0;
    for (int i = 0; i < str_len - 3; i++)
    {
        for (int len = 3; len + i < str_len; len++)
        {
            if (check(i, len))
                ans++;
        }
    }

    std::cout << ans;
}