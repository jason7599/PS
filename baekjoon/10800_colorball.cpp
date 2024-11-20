#include <iostream>
#include <algorithm>

constexpr int max_balls = 200'000;

struct Ball
{
    int color;
    int size;
    int idx;

    const bool operator<(const Ball& other)
    {
        if (size == other.size)
        {
            if (color == other.color)
                return idx < other.idx;
            return color < other.color;
        }
        return size < other.size;
    }
};

Ball balls[max_balls + 1];
int sum_by_color[max_balls + 1];
int sum_by_size[2001];
int ans[max_balls + 1];

int main()
{
    int n_balls;
    std::cin >> n_balls;
    for (int i = 1; i <= n_balls; i++)
    {
        std::cin >> balls[i].color >> balls[i].size;
        balls[i].idx = i;
    }
    
    std::sort(balls + 1, balls + 1 + n_balls);

    int total_sum = 0;

    for (int i = 1; i <= n_balls; i++)
    {
        const Ball& ball = balls[i];

        if (i != 1
        && balls[i - 1].color == ball.color
        && balls[i - 1].size == ball.size)
            ans[ball.idx] = ans[balls[i - 1].idx];
        else
            ans[ball.idx] = total_sum 
            - sum_by_color[ball.color] - sum_by_size[ball.size];

        total_sum += ball.size;
        sum_by_color[ball.color] += ball.size;
        sum_by_size[ball.size] += ball.size;
    }

    for (int i = 1; i <= n_balls; i++)
        std::cout << ans[i] << '\n';
}