#include <iostream>
#include <string>

using namespace std;

string reverse(const string& str)
{
    string rev;
    for (int i = str.length() - 1; i >= 0; i--)
        rev += str[i];
    return rev;
}

int main()
{
    string input; cin >> input;
    string ans;

    for (int len0 = 1; len0 <= input.length() - 2; len0++)
    {
        string str0 = reverse(input.substr(0, len0));
        for (int len1 = 1; len1 <= input.length() - len0 - 1; len1++)
        {
            string str1 = reverse(input.substr(len0, len1));
            string str2 = reverse(input.substr(len0 + len1, input.length() - len0 - len1));

            string str = str0 + str1 + str2;
            if (ans.empty() || str < ans)
                ans = str;
        }
    }

    cout << ans;
    return 0;
}