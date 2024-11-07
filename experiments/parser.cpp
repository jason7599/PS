#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> parse(const string& line, char c = ' ')
{
    vector<string> res;

    size_t pos = 0;
    size_t next;
    while ((next = line.find(c, pos)) != string::npos)
    {
        if (next - pos > 0)
            res.push_back(line.substr(pos, next - pos));
        pos = next + 1;
    }
    if (pos < line.length())
        res.push_back(line.substr(pos));

    return res;
}

int main()
{
    cout << "Enter line: ";

    string line;
    getline(cin, line);

    auto parsed = parse(line);
    for (int i = 0; i < parsed.size(); i++)
        cout << '[' << i << "]: " << parsed[i] << endl;

    return 0;
}