#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cnt[26] = {0};
    int nzc = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            if (!cnt[c - 'A']++)
                nzc++;
        }
    }

    bool is_anagram = 1;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            if (--cnt[c - 'A'] < 0)
            {
                is_anagram = 0;
                break;
            }
            if (cnt[c - 'A'] == 0)
                nzc--;
        }
    }

    is_anagram &= !nzc;

    cout << "Is ";
    if (!is_anagram)
        cout << "not ";
    cout << "an anagram.";

    return 0;
}