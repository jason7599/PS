#include <iostream>
#include <string>

const int max_val = 1e6;

int arr[max_val + 1]; // sum

bool check(int n)
{
    std::string str = std::to_string(n);

    if (str.length() < 3)
        return 0;
    
    bool inc = 1;
    int prev = str.front() - '0';
    for (size_t i = 1; i < str.length(); i++)
    {
        int cur = str[i] - '0';

        if (cur == prev)
            return 0;

        if (inc)
        {
            if (cur < prev)
            {
                if (i == 1)
                    return 0;
                inc = 0;
            }
        }
        else // exp dec
        {
            if (cur > prev)
                return 0;
        }

        prev = cur;
    }

    return !inc;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    for (int i = 1; i <= max_val; i++)
        arr[i] = arr[i - 1] + check(i);

    int t;
    std::cin >> t;
    while (t--)
    {
        int start, end;
        std::cin >> start >> end;
        std::cout << arr[end] - arr[start - 1] << '\n';
    }
}