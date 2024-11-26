#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s; cin >> s;
    stack<char> stack;
    int ans = 0;

    for (char c : s)
    {
        if (c == ')')
        {
            if (stack.empty())
                ans++;
            else
                stack.pop();
        }
        else
            stack.push(c);
    }

    cout << ans + stack.size();
}