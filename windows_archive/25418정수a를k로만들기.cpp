#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1e6;

int solve(int a, int k)
{
    static bool v[MAX +1];
    queue<int> q ({a});
    v[a] = 1;

    int t = 0;
    int s;
    while ((s = q.size()))
    {
        while (s--)
        {
            int n = q.front();
            q.pop();

            if (n == k)
                return t;

            if (!v[n + 1])
            {
                v[n + 1] = 1;
                q.push(n + 1);
            }
            if (n * 2 <= k && !v[n * 2])
            {
                v[n * 2] = 1;
                q.push(n * 2);
            }
        }
        t++;
    }
    return -1;
}

int main()
{
    int a, k;
    cin >> a >> k;
    cout << solve(a, k);
    return 0;
}