#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_files;
    cin >> num_files;

    vector<string> extensions(num_files);

    for (int i = 0; i < num_files; i++)
    {
        string file, extension;
        cin >> file;
        bool read_extension = 0;
        for (char c : file)
        {
            if (read_extension)
                extension += c;
            else if (c == '.')
                read_extension = 1;
        }

        extensions[i] = extension;
    }

    sort(extensions.begin(), extensions.end());

    int cnt = 1;
    string prev = extensions.front();
    for (int i = 1; i < extensions.size(); i++)
    {
        if (extensions[i] == prev)
            cnt++;
        else
        {
            cout << prev << ' ' << cnt << '\n';
            prev = extensions[i];
            cnt = 1;
        }
    }

    cout << prev << ' ' << cnt << '\n';

    return 0;
}