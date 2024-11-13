#include <iostream>

struct Swap
{
    int l;
    int r;
    int cost;
};

int arr_len;
int arr[8];

int swap_cnt;
Swap swaps[10];

bool check()
{
    for (int i = 1; i < arr_len; i++)
    {
        if (arr[i - 1] > arr[i])
            return 0;
    }
    return 1;
}

int brute()
{
    if (check())
        return 0;

    for (int s = 0; s < swap_cnt; s++)
    {
        int l = swaps[s].l - 1;
        int r = swaps[s].r - 1;

    }
}

int main()
{
    std::cin >> arr_len;
    for (int i = 0; i < arr_len; i++)
        std::cin >> arr[i];

    std::cin >> swap_cnt;
    for (int i = 0; i < swap_cnt; i++)
        std::cin >> swaps[i].l >> swaps[i].r >> swaps[i].cost;
    

}