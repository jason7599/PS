#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Word
{
    string str;
    int freq;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_words, min_length;
    cin >> num_words >> min_length;

    map<string, int> dict;

    while (num_words--)
    {
        string str; cin >> str;

        if (str.length() >= min_length)
        {
            
        }
    }
}