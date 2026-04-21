#include <bits/stdc++.h>

int get_max_val(const std::vector<int>& arr, std::vector<int>& cache, size_t idx = 0)
{   
    if (idx >= arr.size())
        return 0;
    
    int& res = cache[idx];
    if (res)
        return res;

    res = arr[idx] + get_max_val(arr, cache, idx + 2);

    if (idx + 1 != arr.size())
        res = std::max(res, arr[idx + 1] + get_max_val(arr, cache, idx + 3));

    return res;
}

int solve_row(const std::vector<int>& row)
{
    std::vector<int> cache(row.size());
    return get_max_val(row, cache);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (1)
    {
        int height, width;
        std::cin >> height >> width;

        if (!height && !width)
            break;

        std::vector<int> y_axis(height);

        for (int& y : y_axis)
        {
            std::vector<int> x_axis(width);

            for (int &x : x_axis)
                std::cin >> x;
                
            y = solve_row(x_axis);
        }

        std::cout << solve_row(y_axis) << '\n';
    }
}