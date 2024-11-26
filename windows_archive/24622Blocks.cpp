#include <iostream>
#include <string>

using namespace std;

bool block_letters[4][26];

bool can_spell(const string& word, int index = 0)
{
    static bool block_used[4];

    if (index == word.length())
        return 1;
    
    for (int b = 0; b < 4; b++)
    {
        if (!block_used[b])
        {
            if (block_letters[b][word[index] - 'A'])
            {
                block_used[b] = 1;
                bool res = can_spell(word, index + 1);
                block_used[b] = 0;
                if (res)
                    return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int num_words;
    cin >> num_words;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            char c;
            cin >> c;
            block_letters[i][c - 'A'] = 1;
        }
    }

    while (num_words--)
    {
        string word;
        cin >> word;

        if (can_spell(word))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}