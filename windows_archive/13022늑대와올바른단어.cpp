#include <iostream>
#include <string>

using namespace std;

const string wolf = "wolf";

int get_len(const string& str, char c, int off)
{
    int len = 0;
    while (off < str.length() && str[off++] == c)
        len++;
    return len;
}

int main()
{
    string str;
    cin >> str;

    int exp_idx = 0;
    int factor;

    int i = 0;
    bool good = 1;
    while (i < str.length())
    {
        int len = get_len(str, wolf[exp_idx], i);

        if (exp_idx == 0) // 'w', define factor
        {
            if (len == 0)
            {
                good = 0;
                break;
            }

            factor = len;
        }
        else
        {
            if (len != factor)
            {
                good = 0;
                break;
            }
        }

        if (++exp_idx == 4)
        {
            exp_idx = 0;
        }

        i += len;
    }

    if (exp_idx)
        good = 0;

    cout << good;

    return 0;
}