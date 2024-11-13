#include <iostream>
#include <algorithm>

int arr[1'000'000];

int main()
{
    int arr_len;
    std::cin >> arr_len;

    for (int i = 0; i < arr_len; i++)
        std::cin >> arr[i];

    int max_len = 0;
    for (int l = 0; l < arr_len; l++)
    {
        int v = arr[l];
        int len = 1;
        int r = l + 1;
        while (r < arr_len)
        {
            if (v & arr[r])
            {
                v &= arr[r];
                len++;
            }
            r++;
        }

        max_len = std::max(max_len, len);
    }

    std::cout << max_len;
}