#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int m_height, m_width;
    std::cin >> m_height >> m_width;

    std::vector<int> terrain(m_width);
    std::unordered_map<int, std::queue<int>> h_queues;

    for (int x = 0; x < m_width; x++)
    {
        int height;
        std::cin >> height;

        terrain[x] = height;

        if (x)
        {
            while (height)
                h_queues[height--].push(x);
        }
    }

    int x = 0;
    int total_rain = 0;
    while (x < m_width)
    {
        int height = terrain[x];

        while (height > 0)
        {
            if (!h_queues.count(height))
            {
                height--;
                continue;
            }

            auto& h_queue = h_queues.at(height);

            int nx;
            while ((nx = h_queue.front()) <= x)
            {
                h_queue.pop();
                if (h_queue.empty())
                    break;
            }

            if (h_queue.empty())
            {
                height--;
                continue;
            }

            for (++x; x < nx; x++)
                total_rain += height - terrain[x];
            
            x--;

            break;
        }

        x++;
    }

    std::cout << total_rain << '\n';
}
