#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    if (s.length() > t.length())
    {
        string x = s;
        s = t;
        t = x;
    }

    if (t.substr(0, s.length()) == s)
    {
        
    }
}