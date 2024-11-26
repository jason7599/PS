#include <iostream>
#include <string>

using namespace std;

int solve(const string& str)
{
    int next_num = 1;
    int i = 0;

    while (i < str.length())
    {
        string num_str = to_string(next_num);
        // int j = 0;
        // while (j < num_str.length() && i < str.length() && str[i] == num_str[j])
        //     i++, j++;
        for (int j = 0; j < num_str.length() && i < str.length(); j++)
        {
            if (str[i] == num_str[j])
                i++;
        }
        next_num++;
    }

    return next_num - 1;
}

int main()
{
    string str;
    cin >> str;

    cout << solve(str);
    return 0;
}