#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int q_size, n_targets;
    std::cin >> q_size >> n_targets;

    std::deque<int> dq(q_size);

    for (int i = 0; i < q_size; i++)
        dq[i] = i + 1;
    
    int n_ops = 0;

    while (n_targets--)
    {
        int target;
        std::cin >> target;

        int dist = 0;
        while (dq.front() != target)
        {
            dq.push_back(dq.front());
            dq.pop_front();
            dist++;
        }

        n_ops += std::min(dist, (int)dq.size() - dist);
        dq.pop_front();
    }

    std::cout << n_ops << '\n';
}