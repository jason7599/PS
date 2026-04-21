#include <iostream>
#include <stack>
#include <string>

// char, # contiguous
std::stack<std::pair<char, int>> stack;

void push_a()
{
    if (stack.empty() || stack.top().first != 'A')
        stack.push({'A', 1});
    else
        stack.top().second++;
}

void push_b()
{
    if (stack.empty() || stack.top().first != 'B')
    {
        stack.push({'B', 1});
        return;
    }

    if (++stack.top().second != 2)
        return;

    // BB
    if (stack.size() == 1)
        return;

    // now guaranteed to have at least 1 A on top
    stack.pop();

    // ABB -> BA
    if (!--stack.top().second)
        stack.pop();

    push_b();
    push_a();
}

void print_and_clear_stack()
{
    if (stack.empty())
        return;

    const auto [c, cnt] = stack.top();
    stack.pop();

    print_and_clear_stack();

    std::cout << std::string(cnt, c);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int len;
        std::cin >> len;

        while (len--)
        {
            char c;
            std::cin >> c;

            if (c == 'A')
                push_a();
            else
                push_b();
        }

        print_and_clear_stack();
        std::cout << '\n';
    }
}