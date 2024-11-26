#include <iostream>
#include <stack>

using namespace std;

int main()
{
    const int p_val = 1;
    const int pp_val = 2;
    const int ppa_val = 3;

    if (getchar() != 'P')
    {
bad:
        printf("NP");
        return 0;
    }

    stack<int> stack;
    stack.push(p_val);

    while (true)
    {
        char c = getchar();

        if (c == 'P')
        {
            switch (stack.top())
            {
                // p + p => pp
                case p_val: 
                stack.top() = pp_val;
                break;

                // pp + p => p, pp
                // ex: ppppp => p, p, p, pp
                case pp_val:
                stack.top() = p_val;
                stack.push(pp_val);
                break;

                // ppa + p => pop ppap, push p;
                case ppa_val:
                if (stack.size() == 1)
                    stack.top() = p_val;
                else
                {
                    stack.pop();
                    // if (stack.top() != p_val)
                    // {
                    //     printf("WTF %d\n", stack.top());
                    //     goto bad;
                    // }
                    stack.top() = pp_val;
                }
                break;
            }
        }
        else if (c == 'A')
        {
            if (stack.top() == pp_val)
                stack.top() = ppa_val;
            else
                goto bad;
        }
        else
            break;
    }

    if (stack.size() != 1 || stack.top() != p_val)
        goto bad;

    printf("PPAP");
}