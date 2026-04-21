#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n_ops;
    std::cin >> n_ops;

    std::deque<int> dq;

    while (n_ops--)
    {
        std::string op;
        std::cin >> op;

        if (op == "push_front")
        {
            int x;
            std::cin >> x;
            dq.push_front(x);
        }
        else if (op == "push_back")
        {
            int x;
            std::cin >> x;
            dq.push_back(x);
        }
        else if (op == "pop_front")
        {
            if (dq.empty())
                std::cout << -1 << '\n';
            else
            {
                std::cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (op == "pop_back")
        {
            if (dq.empty())
                std::cout << -1 << '\n';
            else
            {
                std::cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (op == "size")
            std::cout << dq.size() << '\n';
        else if (op == "empty")
            std::cout << dq.empty() << '\n';
        else if (op == "front")
            std::cout << (dq.empty() ? -1 : dq.front()) << '\n';
        else if (op == "back")
            std::cout << (dq.empty() ? -1 : dq.back()) << '\n';
    }
}