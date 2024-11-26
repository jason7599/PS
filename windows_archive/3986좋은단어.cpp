#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int ans = 0;
    while (t--)
    {
        string line;
        cin >> line;

        stack<char> s;

        for (char c : line)
        {
            if (s.empty())
                s.push(c);
            else
            {
                if (c == s.top())
                    s.pop();
                else
                    s.push(c);
            }
        }

        if (s.empty())
            ans++;
    }

    cout << ans;
}