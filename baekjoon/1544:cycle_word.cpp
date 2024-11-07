#include <iostream>
#include <string>

using namespace std;

bool is_equivalent(const string& str0, const string& str1)
{
    size_t len = str0.length();

    if (len != str1.length())
        return 0;

    size_t pos = 0;
    while ((pos = str0.find(str1[0], pos)) != string::npos)
    {
        bool match = 1;
        for (size_t i = 1; i < len; i++)
        {
            if (str0[(pos + i) % len] != str1[i])
            {
                match = 0;
                break;
            }
        }

        if (match)
            return 1;
            
        pos++;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_input;
    cin >> num_input;

    string words[50];
    int num_words = 0;

    while (num_input--)
    {
        string str;
        cin >> str;

        bool is_unique = 1;
        for (int i = 0; i < num_words; i++)
        {
            if (is_equivalent(words[i], str))
            {
                is_unique = 0;
                break;
            }
        }

        if (is_unique)
            words[num_words++] = str;
    }

    cout << num_words;
    return 0;
}