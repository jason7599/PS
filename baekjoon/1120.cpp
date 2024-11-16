#include <iostream>
#include <string>
#include <algorithm>

int solve(const std::string& start, const std::string& dest)
{
    int min_diff = start.length();
    for (size_t d = 0; d <= dest.length() - start.length(); d++)
    {
        int diff = 0;
        for (size_t s = 0; s < start.length(); s++)
        {
            if (start[s] != dest[d + s])
                diff++;
        }
        min_diff = std::min(min_diff, diff);
    }
    return min_diff;
}

int main()
{
    std::string start, dest;
    std::cin >> start >> dest;
    std::cout << solve(start, dest);
}