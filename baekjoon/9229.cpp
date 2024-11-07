#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        vector<string> words;

        while (1)
        {
            string word;
            cin >> word;

            if (word == "#")
                break;

            words.push_back(word);
        }

        if (words.empty())
            break;

        bool res = 1;
        for (int i = 1; i < words.size(); i++)
        {
            if (words[i].length() != words[i - 1].length())
            {
                res = 0;
                break;
            }

            bool diff = 0;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (words[i][j] != words[i - 1][j])
                {
                    if (diff)
                    {
                        diff = 0;
                        break;
                    }
                    diff = 1;
                }
            }

            if (!diff)
            {
                res = 0;
                break;
            }
        }

        if (res)
            cout << "Correct\n";
        else
            cout << "Incorrect\n";
    }

    return 0;
}