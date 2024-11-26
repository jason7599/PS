#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ctoi(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a';
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    return -1;
}

int pangram(const string& str)
{
    int count[26] = {0};

    for (char c : str)
    {
        int i = ctoi(c);
        if (i != -1)
            count[i]++;
    }

    int res = 3;
    for (int i = 0; i < 26; i++)
        if ((res = min(res, count[i])) == 0)
            break;

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++)
    {
        string str;
        getline(cin, str);

        cout << "Case " << i << ": ";

        int res = pangram(str);
        switch (res)
        {
            case 0: cout << "Not a pangram"; break;
            case 1: cout << "Pangram!"; break;
            case 2: cout << "Double pangram!!"; break;
            case 3: cout << "Triple pangram!!!"; break;
        }
        cout << '\n';
    }

    return 0;
}