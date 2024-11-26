#include <iostream>
#include <string>

using namespace std;

bool try_palind(string str, int len)
{
    int l = 0, r = len - 1;
    while (l < r)
    {
        if (r >= str.length() || str[r] == str[l])
            l++, r--;
        else
            return false;
    }
    return true;
}

int main()
{
    string str; cin >> str;
    for (int len = str.length();; len++)
    {
        if (try_palind(str, len))
        {
            cout << len;
            break;
        }
    }
    return 0;
}