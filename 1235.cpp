#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_codes;
    std::cin >> n_codes;

    std::vector<std::string> codes(n_codes);

    for (auto& code : codes)
        std::cin >> code;
    
    // Rule of Thumb
    // The range [low, high] should represent all possible candidates for the answer.
    int low = 1;
    int high = codes[0].length();


    while (low < high)
    {
        int mid = (low + high) / 2;

        bool good = 1;
        std::unordered_set<std::string> set;

        for (const auto& code : codes)
        {
            std::string substr = code.substr(code.length() - mid);
            if (set.count(substr))
            {
                good = 0;
                break;
            }
            set.insert(substr);
        }

        // If check(mid) means mid might be part of the answer,
        // we don't want to exclude it. Therefore, high = mid instead of high = mid - 1.
        if (good)
            high = mid;
        else
            // If check(mid) returns false, mid cannot be the answer.
        // Therefore low = mid + 1 to eliminate mid entirely. 
            low = mid + 1;
    }

    // At the end of the loop, low and high converge to the same value.
    // This value represents the smallest valid mid that satisfies check(mid)
    std::cout << low;
}