#include <iostream>
#include <string>

size_t len;
int cnt[26];

int solve(size_t idx = 0, int prev = -1)
{
    if (idx == len)
        return 1;
    
    int res = 0;

    for (int i = 0; i < 26; i++)
    {
        if (i == prev || !cnt[i])
            continue;
    
        cnt[i]--;
        res += solve(idx + 1, i);
        cnt[i]++;
    }

    return res;
}

int main()
{
    std::string str;
    std::cin >> str;

    for (char c : str)
    {
        cnt[c - 'a']++;
        len++;
    }
    
    std::cout << solve();
}