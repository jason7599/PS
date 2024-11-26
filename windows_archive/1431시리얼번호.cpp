#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string& s0, const string& s1)
{
    if (s0.length() == s1.length())
    {
        int v0 = 0, v1 = 0;
        for (int i = 0; i < s0.length(); i++)
        {
            if ('0' <= s0[i] && s0[i] <= '9')
                v0 += s0[i] - '0';

            if ('0' <= s1[i] && s1[i] <= '9')
                v1 += s1[i] - '0';
        }

        if (v0 == v1)
        {
            return s0 < s1;
        }
        else
        {
            return v0 < v1;
        }
    }
    else
    {
        return s0.length() < s1.length();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_strs;
    string strs[50];

    cin >> num_strs;
    for (int i = 0; i < num_strs; i++)
        cin >> strs[i];

    sort(strs, strs + num_strs, compare);

    for (int i = 0; i < num_strs; i++)
        cout << strs[i] << '\n';

    return 0;
}