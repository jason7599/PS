#include <iostream>
#include <queue>
#include <algorithm>

struct Rect
{
    int left, right;
    int height;

    Rect(int _left, int _right, int _height)
        : left(_left), right(_right), height(_height) {}

    bool operator<(const Rect& other) const
    {
        return left < other.left;
    }
};

int main()
{
    int n_buildings;
    std::cin >> n_buildings;
    std::vector<Rect> rects;

    while (n_buildings--)
    {
        int left, right, height;
        std::cin >> left >> height >> right;
        rects.push_back(Rect(left, right, height));
    }

    std::sort(rects.begin(), rects.end());

    // 아직 안끝난 rect, 높이 큰 순으로.
    std::priority_queue<Rect> pq;

    for (const Rect& rect : rects)
    {
        if (!pq.empty() && pq.top().right <= rect.left)
        {
            std::cout << pq.top().left << ' ' << pq.top().height << ' ';
            int end = pq.top().right;
            while (!pq.empty() && pq.top().right <= rect.left)
            {
                if (pq.top().right > end)
                
            }
        }

        // while (!pq.empty() && pq.top().right <= rect.left)
        // {
        //     int r = pq.top().right;
            
        // }

        if (pq.empty()
        || (pq.top().height < rect.height))
        {
            std::cout << rect.left << ' ' << rect.height << ' ';
        }

        pq.push(rect);
    }
}