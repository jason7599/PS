#include <iostream>
#include <string>

using namespace std;

const int mod = 1'000'000;

int solve(const string& password, int index = 0)
{
    static int dp[5'000];

    if (index >= password.length())
        return 0;

    if (dp[index])
        return dp[index];
    
    int res = solve(password, index + 1);

    if (index + 2 < password.length())
    {
        if ((password[index] - '0') * 10 + (password[index + 1] - '0') <= 26)
            res += solve(password, index + 2);
    }
}

int main()
{
    string password;
    cin >> password;

    return 0;
}