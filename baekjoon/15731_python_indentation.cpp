#include <iostream>
#include <string>

const int MOD = 1e9 + 7;

int solve(const std::string& str, size_t idx = 0, int indent = 0)
{
    static int cache[5000][5000];

    int& res = cache[idx][indent];
    
    if (res)
        return res;

    while (str[idx] == 'f')
    {
        idx++;
        indent++;
    }

    if (idx == str.length() - 1)
        res = 1;
    else
    {
        for (int nx_indent = 0; nx_indent <= indent; nx_indent++)
            res = (res + solve(str, idx + 1, nx_indent) % MOD) % MOD;
    }
    
    return res;
}

int main()
{
    std::string str;
    std::cin >> str;
}

