#include <iostream>
#include <functional>

struct Op
{
    char c;
    std::function<int(int, int)> func;
};

const Op OPS[] = 
{
    Op{'+', [](int a, int b) { return a + b; }},
    Op{'-', [](int a, int b) { return a - b; }},
    Op{'*', [](int a, int b) { return a * b; }},
    Op{'/', [](int a, int b) { return a % b ? -1 : a / b; }}
};

std::pair<char, char> solve(int nums[3])
{
    for (int i = 0; i < 2; i++)
    {
        int res = i ? nums[0] : nums[2];
        for (const Op& op : OPS)
        {
            if (op.func(nums[i], nums[i + 1]) == res)
            {
                char a, b;
                if (i)
                {
                    a = '=';
                    b = op.c;
                }
                else
                {
                    a = op.c;
                    b = '=';
                }

                return {a, b};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    int nums[3];
    for (int& num : nums)
        std::cin >> num;
    
    auto ops = solve(nums);

    std::cout << nums[0] << ops.first << nums[1] << ops.second << nums[2];
}