#include <iostream>
#include <string>

using namespace std;

int main()
{
    string source, target;
    cin >> source >> target;

    int ans = 0;
    size_t i = 0;
    while (i < target.length())
    {
        size_t longest_match = 0;
        size_t match = 0;
        for (char c : source)
        {
            if (c == target[i + match])
            {
                if (++match > longest_match)
                {
                    longest_match = match;
                    if (i + match > target.length())
                        break;
                }
            }
            else
                match = 0;
        }

        i += longest_match;
        ans++;
    }

    cout << ans;
    return 0;
}