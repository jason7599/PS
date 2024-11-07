#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_words;
    cin >> num_words;

    set<string> word_set;

    while (num_words--)
    {
        string word;
        cin >> word;

        string word_sorted = word;
        sort(word_sorted.begin(), word_sorted.end());

        if (word_set.find(word_sorted) == word_set.end())
        {
            cout << word << '\n';
            word_set.insert(word_sorted);
        }
    }

    return 0;
}