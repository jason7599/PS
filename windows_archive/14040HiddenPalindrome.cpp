#include <iostream>
#include <string>

using namespace std;

int solve(const string& str)
{
    for (int len = str.length(); len > 0; len--)
    {
        for (int i = 0; i + len - 1 < str.length(); i++)
        {
            bool is_palindrome = 1;
            for (int d = 0; d < len / 2; d++)
            {
                if (str[i + d] != str[i + len - 1 - d])
                {
                    is_palindrome = 0;
                    break;
                }
            }
            if (is_palindrome)
                return len;
        }
    }
    
    return -1;
}

int main()
{
    string str;
    cin >> str;
    cout << solve(str);
    return 0;
}