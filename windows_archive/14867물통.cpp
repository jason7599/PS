#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

using pii = pair<int, int>;

set<pii> visited;
queue<pii> q;

void push(int a, int b)
{
    if (visited.find({a, b}) == visited.end())
    {
        visited.insert({a, b});
        q.push({a, b});
    }
}

int solve(int a_max, int b_max, int a_dest, int b_dest)
{
    push(0, 0);

    int time = 0;
    int q_size;
    while ((q_size = q.size()) != 0)
    {
        while (q_size--)
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if (a == a_dest && b == b_dest)
                return time;

            // F(A)
            push(a_max, b);

            // F(B)
            push(a, b_max);

            // E(A)
            push(0, b);

            // E(B)
            push(a, 0);

            // M(A, B)
            int b_fill = a + b > b_max ? b_max - b : a;
            push(a - b_fill, b + b_fill);

            // M(B, A);
            int a_fill = a + b > a_max ? a_max - a : b;
            push(a + a_fill, b - a_fill);
        }

        time++;
    }

    return -1;
}

int main()
{
    int a_max, b_max, a_dest, b_dest;

    cin >> a_max >> b_max >> a_dest >> b_dest;

    cout << solve(a_max, b_max, a_dest, b_dest);

    return 0;
}