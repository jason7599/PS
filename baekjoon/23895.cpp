#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;

    for (int tc = 1; tc <= n_tc; tc++)
    {
        int n_houses, budget;
        std::cin >> n_houses >> budget;

        std::priority_queue<int> pq;

        while (n_houses--)
        {
            int price;
            std::cin >> price;
            pq.push(-price);
        }

        int n_houses_bought = 0;
        while (!pq.empty() && -pq.top() <= budget)
        {
            budget += pq.top();
            pq.pop();
            n_houses_bought++;
        }

        std::cout << "Case #" << tc << ": ";
        std::cout << n_houses_bought << '\n';
    }
}