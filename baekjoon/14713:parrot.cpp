#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<string> parse(string str)
{
    queue<string> parsed;

    size_t pos = 0;
    size_t next;

    while ((next = str.find(' ', pos)) != string::npos)
    {
        parsed.push(str.substr(pos, next - pos));
        pos = next + 1;
    }

    parsed.push(str.substr(pos));
    return parsed;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_parrots;
    cin >> num_parrots;
    cin.ignore();

    vector<queue<string>> parrots(num_parrots);

    for (int i = 0; i < num_parrots; i++)
    {
        string line;
        getline(cin, line);
        parrots[i] = parse(line);
    }

    string line;
    getline(cin, line);

    queue<string> words = parse(line);

    int finished_parrot_cnt = 0;
    bool fucked;
    while (!words.empty())
    {
        string word = words.front();
        words.pop();

        fucked = 1;
        for (queue<string>& parrot : parrots)
        {
            if (!parrot.empty() && parrot.front() == word)
            {
                parrot.pop();
                fucked = 0;

                if (parrot.empty())
                    finished_parrot_cnt++;
            }
        }

        if (fucked)
            break;
    }

    fucked |= finished_parrot_cnt != num_parrots;

    if (fucked)
        cout << "Impossible";
    else
        cout << "Possible";
    return 0;
}