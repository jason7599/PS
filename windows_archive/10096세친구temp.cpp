#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int u_len;
    string u;

    cin >> u_len;
    cin >> u;

    if (u_len % 2 == 0)
    {
        cout << "NOT POSSIBLE";
        return 0;
    }

    string ans;

    string u0 = u.substr(0, u_len / 2);
    string u1 = u.substr(u_len / 2 + 1);

    if (u0 == u1)
        ans = u0;

    for (int i = 0; i < u_len / 2; i++)
    {
        // cout << u.substr(0, i) + u.substr(i + 1, u_len / 2 - i) << '\n';

        if (u.substr(0, i) + u.substr(i + 1, u_len / 2 - i) == u1)
        {
            if (ans.empty())
                ans = u1;
            else if (ans != u1)
            {
                cout << "NOT UNIQUE";
                return 0;
            }
        }
    }

    for (int i = 0; i < u_len / 2; i++)
    {
        // cout << u.substr(u_len / 2, i + 1) + u.substr(u_len / 2 + i + 2) << '\n';
        if (u.substr(u_len / 2, i + 1) + u.substr(u_len / 2 + i + 2) == u0)
        {
            if (ans.empty())
                ans = u0;
            else if (ans != u0)
            {
                cout << "NOT UNIQUE";
                return 0;
            }
        }
    }

    if (ans.empty())
    {
        cout << "NOT POSSIBLE";
        return 0;
    }

    cout << ans;
}