#include <iostream>
#include <vector>

/**
 * check if it is possible to allocate the gems to n_students, where
 * each student gets only one color variety, and no student gets allocated
 * more gems than `max_alloc`.
 */
bool check(int n_students, const std::vector<int>& color_cnt, int max_alloc)
{
    int n_alloc = 0;
    for (int cnt : color_cnt)
    {
        // greedily dole out `max_alloc` gems for each color
        n_alloc += cnt / max_alloc;

        // deal with leftovers.
        if (cnt % max_alloc)
            n_alloc++;

        if (n_alloc > n_students)
            return 0;        
    }
    return 1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_students, n_colors;
    std::cin >> n_students >> n_colors;

    std::vector<int> color_cnt(n_colors);
    for (int& cnt : color_cnt)
        std::cin >> cnt;
    
    int low = 1; 
    int high = 1e9; // todo: find better initial range

    while (low < high)
    {
        int mid = (high + low) / 2;
        if (check(n_students, color_cnt, mid))
            high = mid;
        else
            low = mid + 1;
    }

    std::cout << low;
}