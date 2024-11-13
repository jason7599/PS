#include <iostream>
#include <string>
#include <map>

using namespace std;

string squeeze(const string& str)
{
    int char_ids[26] = {0};
    int n_id = 1;

    string res;
    for (char c : str)
    {
        int id = char_ids[c - 'a'];
        if (!id)
            id = char_ids[c - 'a'] = n_id++;
        res += '0' + id - 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_words;
    cin >> num_words;

    map<string, int> map;
    int ans = 0;

    while (num_words--)
    {
        string word;
        cin >> word;

        ans += map[squeeze(word)]++;
    }

    cout << ans;
    return 0;
}