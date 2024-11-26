#include <iostream>
#include <string>

using namespace std;

string str;

bool search(int seq)
{
    string s = to_string(seq);
    for (int i = 0; i < str.length() - s.length() + 1; i++)
    {
        if (str.substr(i, s.length()) == s)
            return true;
    }
    return false;
}

int main()
{
    int len;
    cin >> len;
    
    for (int i = 0; i < len; i++)
    {
        char c;
        cin >> c;
        str += c;
    }

    int i;
    for (i = 0; search(i); i++);

    cout << i;

    return 0;
}