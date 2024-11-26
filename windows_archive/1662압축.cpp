#include <iostream>
#include <string>

using namespace std;

int decompress(string s)
{
    static int index = 0;

    int len = 0;

    while (index < s.length())
    {
        char c = s[index++];
        if (c == '(')
        {
            len--;
            len += (s[index - 2] - '0') * decompress(s);
        }
        else if (c == ')')
            break;
        else
            len++;
    }

    return len;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    cout << decompress(s);
}