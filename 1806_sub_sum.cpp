#include <iostream>
#include <algorithm>

int arr[100'000];

int main()
{
    int arr_len, target_sum;
    std::cin >> arr_len >> target_sum;

    for (int i = 0; i < arr_len; i++)
        std::cin >> arr[i];
    
    int r = 0;
    int min_len = 1e9;
    int sum = 0;
    for (int l = 0; l < arr_len; l++)
    {
        while (r < arr_len && sum < target_sum)
            sum += arr[r++];
        
        if (sum >= target_sum)
            min_len = std::min(min_len, r - l);
        
        sum -= arr[l];
    }

    std::cout << (min_len == 1e9 ? 0 : min_len);
}