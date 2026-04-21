#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::queue<int> q;

    int n_ops;
    std::cin >> n_ops;

    while (n_ops--)
    {
        std::string op;
        std::cin >> op;

        if (op == "push")
        {
            int x;
            std::cin >> x;
            q.push(x);
        }
        else if (op == "pop")
        {
            if (q.empty())
                std::cout << -1 << '\n';
            else
            {
                std::cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (op == "size")
            std::cout << q.size() << '\n';
        else if (op == "empty")
            std::cout << q.empty() << '\n';
        else if (op == "front")
            std::cout << (q.empty() ? -1 : q.front()) << '\n';
        else if (op == "back")
            std::cout << (q.empty() ? -1 : q.back()) << '\n';
    }
}