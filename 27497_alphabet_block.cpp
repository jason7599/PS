#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    deque<char> dq;
    stack<bool> front;

    int t;
    cin >> t;
    while (t--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 3)
        {
            if (!dq.empty())
            {
                if (front.top())
                    dq.pop_front();
                else
                    dq.pop_back();
                front.pop();
            }
        }
        else
        {
            char v;
            cin >> v;

            if (cmd == 2)
                dq.push_front(v);
            else
                dq.push_back(v);
            
            front.push(cmd == 2);
        }
    }

    if (dq.empty())
        cout << 0;
    else
    {
        for (char c : dq)
            cout << c;
    }

    return 0;
}