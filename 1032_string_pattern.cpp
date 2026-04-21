#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_files;
    cin >> num_files;

    string pattern;
    cin >> pattern;

    for (int i = 1; i < num_files; i++)
    {
        string file;
        cin >> file;

        for (int i = 0; i < pattern.length(); i++)
        {
            if (pattern[i] != file[i])
                pattern[i] = '?';
        }
    }

    cout << pattern;
    return 0;
}