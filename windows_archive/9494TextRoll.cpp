#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(const vector<string>& lines)
{
    int col = 0;
    for (const string& line : lines)
    {
        if (col >= line.length())
            continue;

        bool b = 0;

        for (int i = col; i < line.length(); i++)
        {
            if (line[i] == ' ')
            {
                col = i;
                b = 1;
                break;
            }
        }

        if (!b)
            col = line.length() + 1;
    }
    return col + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        int num_lines;
        cin >> num_lines;
        cin.ignore();

        if (!num_lines)
            break;

        vector<string> lines (num_lines);
        for (int l = 0; l < num_lines; l++)
        {
            string line;
            getline(cin, line);
            lines[l] = line;
        }
        cout << solve(lines) << '\n';
    }

    return 0;
}