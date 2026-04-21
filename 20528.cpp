#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int numWords;
    cin >> numWords;

    string word;
    cin >> word;

    char c;
    bool good;
    if ((good = (c = word.front()) == word.back()))
    {
        for (int i = 1; i < numWords; i++)
        {
            cin >> word;
            if (word.front() != c || word.back() != c)
            {
                good = 0;
                break;
            }
        }
    }

    cout << good;
    return 0;
}