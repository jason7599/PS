#include <iostream>
#include <queue>

struct Gem
{
    int weight;
    int value;
};

class Compare
{
public:
    bool operator() (const Gem& lhs, const Gem& rhs)
    {
        if (lhs.weight == rhs.weight)
            return lhs.value > rhs.value;
        return lhs.weight > rhs.weight;
    }
};

int main()
{
    int num_gems, num_bags;
    std::cin >> num_gems >> num_bags;

    // lower weight on top
    std::priority_queue<Gem, std::vector<Gem>, Compare> gem_pq; 

    for (int i = 0; i < num_gems; i++)
    {
        Gem gem;
        std::cin >> gem.weight >> gem.value;
        gem_pq.push(gem);
    }

    // less capacity on top
    std::priority_queue<int, std::vector<int>, std::greater<int>> bag_pq;  

    for (int i = 0; i < num_bags; i++)
    {
        int cap;
        std::cin >> cap;
        bag_pq.push(cap);
    }

    long long ans = 0;

    // pq of values that can be stolen, greatest on top
    std::priority_queue<int> val_pq; 

    while (!bag_pq.empty())
    {
        int cap = bag_pq.top(); // less cap first
        bag_pq.pop();

        // less weight first; this ensures the values in val_pq are available 
        // for the following bags as well
        while (!gem_pq.empty() && gem_pq.top().weight <= cap)
        {
            val_pq.push(gem_pq.top().value);
            gem_pq.pop();
        }

        if (!val_pq.empty())
        {
            ans += val_pq.top();
            val_pq.pop();
        }
    }

    std::cout << ans;
}
