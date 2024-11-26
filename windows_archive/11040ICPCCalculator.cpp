#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_val(const vector<string>& lines, int& index)
{
    int depth = lines[index].length();
    char op = lines[index].back();

    int val = op == '*'; // +: 0, *: 1

    while (++index < lines.size() && lines[index].length() > depth)
    {
        char c = lines[index].back();

        int n_val;
        if ('0' <= c && c <= '9')
            n_val = c - '0';
        else
            n_val = get_val(lines, index);
        
        if (op == '*')
            val *= n_val;
        else
            val += n_val;
    }

    return val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        int num_lines;
        cin >> num_lines;

        if (!num_lines)
            break;

        vector<string> lines;
        for (int i = 0; i < num_lines; i++)
        {
            string line;
            cin >> line;
            lines.push_back(line);
        }

        int index = 0;
        cout << get_val(lines, index) << '\n';
    }

    return 0;
}