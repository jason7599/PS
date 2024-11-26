#include <iostream>
#include <stack>

#define pci pair<char,int>

using namespace std;

int main()
{
    char c;
    stack<pci> stack;
    int value = 0;

    while ((c = getchar()) != EOF && c != '\n')
    {
        pci p = {c, 0};
        char t;
        int v;

        if (c == '(' || c == '[')
        {
            stack.push(p);
        }
        else // closing brackets
        {
            if (stack.empty())
            {
                value = 0;
                break;
            }

            t = stack.top().first;
            v = stack.top().second;

            if (c == ')' && t == '(')
            {
                v = v ? v * 2 : v + 2;
            }
            else if (c == ']' && t == '[')
            {
                v = v ? v * 3 : v + 3;
            }
            else
            {
                value = 0;
                break;
            }

            stack.pop();

            if (stack.empty())
            {
                value += v;
            }
            else
            {
                stack.top().second += v;
            }
        }
    }

    if (!stack.empty())
        value = 0;

    printf("%d", value);
}