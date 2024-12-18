#include <iostream>

int sum_arr[500'000];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int l = 0;
    int r = -1;
    int neg = 0;

    int n_queries;
    std::cin >> n_queries;

    while (n_queries--)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd == 1)
        {
            std::cin >> sum_arr[++r];
            if (r)
                sum_arr[r] += sum_arr[r - 1];
        }
        else
        {
            // int l_sum = sum_arr[]
        }
    }
}