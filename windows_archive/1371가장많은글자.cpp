#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string line;
    int max_cnt = 0;
    while (getline(cin, line))
    {
        for (char c : line)
        {   
            if (c != ' ')
                max_cnt = max(max_cnt, ++cnt[c - 'a']);
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == max_cnt)
            cout << (char)(i + 'a');
    }
}