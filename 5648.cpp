#include <iostream>
#include <string>
#include <queue>

int64_t reverse(const std::string& num)
{
    int64_t res = 0;
    size_t i = num.length();
    while (i--)
        res = res * 10 + (num[i] - '0');
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_elems;
    std::cin >> n_elems;

    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;

    while (n_elems--)
    {
        std::string num;
        std::cin >> num;
        pq.push(reverse(num));
    }

    while (!pq.empty())
    {
        std::cout << pq.top() << '\n';
        pq.pop();
    }
}