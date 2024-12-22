#include <iostream>
#include <algorithm>
#include <stack>

int n_sharks, shark_sizes[200'000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_eat;
    int64_t size;
    std::cin >> n_sharks >> n_eat >> size;

    for (int i = 0; i < n_sharks; i++)
        std::cin >> shark_sizes[i];
    
    std::sort(shark_sizes, shark_sizes + n_sharks);

    std::stack<int> eatables;

    for (int i = 0; i < n_sharks; i++)
    {
        bool done = 0;
        while (shark_sizes[i] >= size)
        {
            if (eatables.empty())
            {
                done = 1;
                break;
            }

            size += eatables.top();
            eatables.pop();

            if (!--n_eat)
            {
                done = 1;
                break;
            }
        }

        if (done)
            break;
        
        eatables.push(shark_sizes[i]);
    }

    while (n_eat && !eatables.empty())
    {
        size += eatables.top();
        eatables.pop();
        n_eat--;
    }

    std::cout << size;
}