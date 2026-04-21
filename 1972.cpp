#include <iostream>
#include <string>

using namespace std;

bool is_surprising(const string& str)
{
    int v[26][26] = {0};

    for (int d = 1; d < str.length() - 1; d++)
    {
        for (int i = 0; i + d < str.length(); i++)
        {
            if (v[str[i] - 'A'][str[i + d] - 'A'] == d)
                return 0;

            v[str[i] - 'A'][str[i + d] - 'A'] = d;
        }
    }

    return 1;
}

int main()
{
    while (1)
    {
        string str;
        cin >> str;

        if (str == "*")
            break;

        cout << str << " is";
        if (!is_surprising(str))
            cout << " NOT";
        cout << " surprising.\n";
    }

    return 0;
}