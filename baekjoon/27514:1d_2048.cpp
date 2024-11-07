#include <iostream>
#include <queue>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int arr_len;
    std::cin >> arr_len;

    std::priority_queue<long long, 
        std::vector<long long>, std::greater<long long>> pq;

    for (int i = 0; i < arr_len; i++)
    {
        long long x;
        std::cin >> x;
        if (x)
            pq.push(x);
    }

    long long max_val = 0;
    while (!pq.empty())
    {
        long long top = pq.top();
        pq.pop();

        max_val = std::max(max_val, top);

        if (!pq.empty() && pq.top() == top)
        {
            pq.pop();
            pq.push(top * 2);
        }
    }

    std::cout << max_val;
}