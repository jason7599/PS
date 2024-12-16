#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;
    while (n_tc--)
    {
        int n_elems;
        std::cin >> n_elems;

        std::priority_queue<int> lower; // lowerhalf, max pq
        std::priority_queue<int, std::vector<int>, std::greater<int>> upper; // min pq

        std::cout << (n_elems + 1) / 2 << '\n';

        for (int i = 0; i < n_elems; i++)
        {
            int x;
            std::cin >> x;

            if (lower.empty() || x <= lower.top())
                lower.push(x);
            else
                upper.push(x);
            
            if (lower.size() > upper.size() + 1)
            {
                upper.push(lower.top());
                lower.pop();
            }
            else if (upper.size() > lower.size())
            {
                lower.push(upper.top());
                upper.pop();
            }
            
            if (i % 2 == 0)
                std::cout << lower.top() << ((i + 2) % 20 ? ' ' : '\n');

        }

        std::cout << '\n';
    }
}