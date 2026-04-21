#include <iostream>
#include <string>
#include <algorithm>

int num_strs, str_len;
std::string strs[(int)5e5];

bool is_similar(int i, int j)
{
    for (int c = 0; c < str_len; c++)
    {
        if (strs[i][c] == strs[j][c])
            return 1;
    }
    return 0;
}

int get_min_deletes(int str_idx)
{
    static int memo[(int)5e5];

    if (memo[str_idx])
        return std::max(memo[str_idx], 0);

    int min_deletes = num_strs - str_idx - 1;
    int deletes = 0;
    for (int other = str_idx + 1; other < num_strs; other++)
    {
        if (is_similar(str_idx, other))
            min_deletes = std::min(min_deletes, deletes + get_min_deletes(other));
        
        deletes++;
    }

    memo[str_idx] = min_deletes ? min_deletes : -1;
    return min_deletes;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> num_strs >> str_len;

    for (int i = 0; i < num_strs; i++)
        std::cin >> strs[i];
    
    int min_deletes = 0;
    for (int i = 0; i < num_strs; i++)
    {
        int deletes = i + get_min_deletes(i);
        min_deletes = std::min(min_deletes, deletes);
    }

    std::cout << min_deletes;
}