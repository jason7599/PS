#include <iostream>
#include <string>

const int MOD = 1e9 + 7;

// int solve(const std::string& str, size_t idx = 0, int indent = 0)
// {
//     static int cache[5000][5000];

//     int& res = cache[idx][indent];
    
//     if (res)
//         return res;

//     while (str[idx] == 'f')
//     {
//         idx++;
//         indent++;
//     }

//     if (idx == str.length() - 1)
//         res = 1;
//     else
//     {
//         for (int nx_indent = 0; nx_indent <= indent; nx_indent++)
//             res = (res + solve(str, idx + 1, nx_indent) % MOD) % MOD;
//     }

//     if (!res)
//         1 / 0;
    
//     return res;
// }

int main()
{
    std::string str;
    std::cin >> str;

    static int dp[5001][5000]; // dp[len][indent]

    dp[0][0] = 1;

    for (size_t len = 1; len <= str.length(); len++)
    {
        char c = str.at(len - 1);

        for (int indent = 0; indent < str.length(); indent++)
        {
            if (c == 'f')
                
        }
    }
}

