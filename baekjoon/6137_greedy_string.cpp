#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    deque<char> dq;

    while (n--)
    {
        char c;
        cin >> c;
        dq.push_back(c);
    }

    int i = 0;
    while (dq.size() > 1)
    {
        if (dq.front() > dq.back())
        {
            cout << dq.back();
            dq.pop_back();
        }
        else
        {
            cout << dq.front();
            dq.pop_front();
        }
        if (++i % 80 == 0)
            cout << endl;
    }

    cout << dq.back();

    return 0;
}