#include <iostream>
#include <string>
#include <queue>

using namespace std;

const char ops[] = {'D', 'S', 'L', 'R'};

int doop(int val, char op)
{
    switch (op)
    {
        case 'D':
        return (val * 2) % 10'000;
        case 'S':
        if (--val < 0)
            val = 9999;
        return val;
        case 'L':
        return (val % 1000) * 10 + val / 1000;
        case 'R':
        return (val % 10) * 1000 + val / 10;
        default:
        return -1;
    }
}

string solve(int start, int dest)
{
    bool visited[10'000] = {false};
    queue<pair<int, string>> q;

    visited[start] = true;
    q.push({start, ""});

    while (true)
    {
        int q_size = q.size();
        while (q_size--)
        {
            int val = q.front().first;
            string opstr = q.front().second;
            q.pop();

            if (val == dest)
            {
                return opstr;
            }

            for (char op : ops)
            {
                int next_val = doop(val, op);
                if (!visited[next_val])
                {
                    visited[next_val] = true;
                    q.push({next_val, opstr + op});
                }
            }
        }
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int start, dest;
        cin >> start >> dest;
        cout << solve(start, dest) << '\n';
    }
    return 0;
}