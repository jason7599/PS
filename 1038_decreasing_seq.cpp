#include <iostream>
#include <string>

std::string ans;

bool brute(int len, int start, int n)
{
    static int i;

    ans.push_back('0' + start);

    if (len == 1)
    {
        if (i++ == n)
            return 1;
        
        ans.pop_back();
        return 0;
    }

    for (int next = 0; next < start; next++)
    {
        if (brute(len - 1, next, n))
            return 1;
    }

    ans.pop_back();
    return 0;
}

int main()
{
    int n;
    std::cin >> n;

    for (int len = 1; len <= 10; len++)
    {
        for (int start = 0; start <= 9; start++)
        {
            if (brute(len, start, n))
            {
                std::cout << ans;
                return 0;
            }
        }
    }

    std::cout << -1;
}