#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int solve(const string& start)
{
    set<string> visited;
    queue<string> q;

    visited.insert(start);
    q.push(start);

    int moves = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            string str = q.front();
            q.pop();

            if (str == "0")
                return moves;

            string m1 = to_string(stoi(str) - 1);
            if (visited.find(m1) == visited.end())
            {
                visited.insert(m1);
                q.push(m1);
            }

            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '1')
                {
                    string left = str.substr(0, i);
                    string right = str.substr(i + 1, string::npos);

                    if (left.empty() && right.empty())
                        break;

                    string nstr = to_string(stoi(left + right));
                    if (visited.find(nstr) == visited.end())
                    {
                        visited.insert(nstr);
                        q.push(nstr);
                    }
                }
            }
        }

        moves++;
    }

    return -1;
}

int main()
{
    string input;
    cin >> input;

    cout << solve(input);

    return 0;
}