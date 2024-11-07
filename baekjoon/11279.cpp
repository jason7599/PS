#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    priority_queue<int> pq;

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x)
            pq.push(x);
        else
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}