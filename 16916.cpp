#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_kmp_table(const string& pattern)
{
    vector<int> kmp_table(pattern.length());

    int pos = 1; // current index to compute in table 
    int cnd = 0; // index in pattern 

    kmp_table[0] = -1;

    while (pos < pattern.length())
    {
        if (pattern[pos] == pattern[cnd])
            kmp_table[pos] = kmp_table[cnd];
        else
        {
            kmp_table[pos] = cnd;
            while (cnd >= 0 && pattern[pos] != pattern[cnd])
                cnd = kmp_table[cnd];
        }
        pos++;
        cnd++;
    }

    return kmp_table;
}

bool kmp_find(const string& str, const string& pattern)
{
    vector<int> kmp_table = get_kmp_table(pattern);

    int i = 0; // index for str
    int j = 0; // index for pattern

    while (i < str.length())
    {
        if (str[i] == pattern[j])
        {
            i++;
            if (++j == pattern.length())
                return 1;
        }
        else
        {
            j = kmp_table[j];
            if (j < 0) // j = -1
            {
                i++; 
                j++; // j = 0;
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s, p;
    cin >> s >> p;
    cout << kmp_find(s, p);
    return 0;
}   