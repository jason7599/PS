#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int num_ops, x;
    stack<int> stack;
    string op;

    cin >> num_ops;

    while (num_ops--)
    {
        cin >> op;

        if (op == "push")
        {
            cin >> x;
            stack.push(x);
        }
        else if (op == "pop")
        {
            if (stack.empty())
            {
                x = -1;
            }
            else
            {
                x = stack.top();
                stack.pop();
            }

            cout << x << '\n';
        }
        else if (op == "size")
        {
            cout << stack.size() << '\n';
        }
        else if (op == "empty")
        {
            cout << stack.empty() << '\n';
        }
        else if (op == "top")
        {
            cout << (stack.empty() ? -1 : stack.top()) << '\n';
        }
    }
}