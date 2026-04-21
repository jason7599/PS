#include <iostream>
#include <algorithm>

int gaps[250'000];

struct Birdie
{
    int size;
    int idx;

    bool operator<(const Birdie& other) const 
    {
        return size > other.size;
    }
};

Birdie birdies[250'000];
int scores[250'000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_obstacles;
    std::cin >> n_obstacles;

    for (int d = 1; d >= -1; d -= 2)
    {
        for (int i = 0; i < n_obstacles; i++)
        {
            int x;
            std::cin >> x;
            gaps[i] += x * d;
        }
    }

    int n_birdies;
    std::cin >> n_birdies;

    for (int i = 0; i < n_birdies; i++)
    {
        std::cin >> birdies[i].size;
        birdies[i].idx = i;
    }

    // biggest size first
    std::sort(birdies, birdies + n_birdies);

    int top_birdie = 0;
    int score = 0;
    
    for (int o = 0; o < n_obstacles; o++)
    {
        while (top_birdie < n_birdies
            && gaps[o] < birdies[top_birdie].size)
        {
            scores[birdies[top_birdie].idx] = score;
            top_birdie++;
        }

        if (top_birdie == n_birdies)
            break;

        score++;
    }

    for (; top_birdie < n_birdies; top_birdie++)
        scores[birdies[top_birdie].idx] = score;

    for (int i = 0; i < n_birdies; i++)
        std::cout << scores[i] << '\n';
}