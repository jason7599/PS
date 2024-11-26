#include <iostream>
#include <string>

using namespace std;

bool isLegitPalindrome(string str, int left, int right)
{
    while (left < right)
        if (str[left++] != str[right--])
            return false;
    return true;
}

int evaluate(string str)
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (str[left] == str[right])
        {
            left++; 
            right--;
        }
        else
        {
            if (isLegitPalindrome(str, left + 1, right) || isLegitPalindrome(str, left, right - 1))
                return 1;
            return 2;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        string str; cin >> str;
        cout << evaluate(str) << '\n';
    }
}