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

size_t kmp_find(const string& str, const string& pattern)
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
                return i - j;
        }
        else
        {
            j = kmp_table[j];
            if (j < 0)
            {
                i++;
                j++;
            }
        }
    }

    return -1;
}

int main()
{
    const string pattern = "abacababc";

    const auto kmp_table = get_kmp_table(pattern);

    for (int i = 0; i < kmp_table.size(); i++)
    {
        cout << i << " : " << kmp_table[i] << '\n';
    }

    return 0;
}