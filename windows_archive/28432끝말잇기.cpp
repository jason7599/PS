#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_words;
    cin >> num_words;

    char first = '?';
    char last = '?';
    string prev;
    set<string> words;

    for (int i = 0; i < num_words; i++)
    {
        string word;
        cin >> word;

        if (word == "?")
        {
            if (i != 0)
                first = prev[prev.length() - 1];
        }
        else
        {
            if (i != 0)
            {
                if (prev == "?")
                    last = word[0];
            }
            words.insert(word);
        }
        prev = word;
    }

    int num_candidates;
    cin >> num_candidates;

    for (int i = 0; i < num_candidates; i++)
    {
        string candidate;
        cin >> candidate;

        if (words.find(candidate) != words.end())
            continue;
        
        if ((first == '?' || candidate[0] == first)
        && (last == '?' || candidate[candidate.length() - 1] == last))
        {
            cout << candidate;
            return 0;
        }
    }
}