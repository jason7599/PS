#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string infix;
    cin >> infix;

    stack<char> ops;
    string postfix;

    char t;

    for (char c : infix)
    {
        if (c == '(' || c == '*' || c == '/')
        {
            ops.push(c);
        }
        else if (c == '+' || c == '-')
        {
            if (!ops.empty())
            {
                t = ops.top();

                if (t == '*' || t == '/')
                {
                    postfix += t;
                    ops.pop();

                    while (!ops.empty() && (t = ops.top()) != '(')
                    {
                        postfix += t;
                        ops.pop();
                    }
                }
            }

            ops.push(c);
        }
        else if (c == ')')
        {
            while ((t = ops.top()) != '(')
            {
                postfix += t;
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            postfix += c;
        }
    }

    while (!ops.empty())
    {
        postfix += ops.top();
        ops.pop();
    }

    cout << postfix;
}