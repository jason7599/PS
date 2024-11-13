#include <iostream>
#include <string>

using namespace std;

void check(const string& current_word, string& longest_word)
{
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string longest_word;

    while (1)
    {
        string line;
        getline(cin, line);

        string current_word;

        for (char c : line)
        {
            if (c == '-'
            || ('a' <= c && c <= 'z')
            || ('A' <= c && c <= 'Z'))
                current_word += c;
            else
            {
                if (!current_word.empty())
                {
                    if (current_word == "E-N-D")
                        break;

                    if (current_word.length() > longest_word.length())
                        longest_word = current_word;
                    current_word.clear();
                }
            }
        }

        if (!current_word.empty())
        {
            if (current_word == "E-N-D")
                    break;
            if (current_word.length() > longest_word.length())
                longest_word = current_word;
            current_word.clear();
        }
    }

    for (char c : longest_word)
    {

    }
    return 0;
}