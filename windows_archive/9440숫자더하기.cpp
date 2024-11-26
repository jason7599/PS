#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        int n;
        cin >> n;

        if (!n)
            break;

        int num_zeros = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x)
                pq.push(x);
            else
                num_zeros++;
        }

        int vals[2];
        vals[0] = pq.top(); pq.pop();
        vals[1] = pq.top(); pq.pop();
        n -= 2;

        bool b = 0;
        while (n)
        {
            int v;
            if (num_zeros)
            {
                v = 0;
                num_zeros--;
            }
            else
            {
                v = pq.top();
                pq.pop();
            }

            n--;
            
            vals[b] = vals[b] * 10 + v;

            b = !b;
        }

        cout << vals[0] + vals[1] << '\n';
    }

    return 0;
}