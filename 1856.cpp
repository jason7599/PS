#include <iostream>
#include <string>
#include <algorithm>

int num_words;
std::string str, words[600];

int solve(size_t s_idx = 0)
{
    static int memo[300];

    if (s_idx == str.length())
        return 0;
    
    if (memo[s_idx])
        return memo[s_idx];

    int min_dels = str.length() - s_idx;
    for (int w = 0; w < num_words; w++)
    {
        const auto& word = words[w];
        int dels = 0;
        
        size_t ts_idx = s_idx;
        size_t c_idx = 0;
        for (; c_idx < word.length(); c_idx++)
        {
            while (ts_idx < str.length() && word[c_idx] != str[ts_idx])
            {
                dels++;
                ts_idx++;
            }

            if (ts_idx == str.length())
                break;
            
            ts_idx++;
        }

        if (c_idx == word.length())
            min_dels = std::min(min_dels, dels + solve(ts_idx));
    }

    return memo[s_idx] = min_dels;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int str_len;
    std::cin >> num_words >> str_len;
    std::cin >> str;

    for (int i = 0; i < num_words; i++)
        std::cin >> words[i];

    std::cout << solve();
}