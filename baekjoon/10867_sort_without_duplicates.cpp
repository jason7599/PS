#include <iostream>
#include <algorithm>

int arr[100'000];

int main()
{
    int len;
    std::cin >> len;
    for (int i = 0; i < len; i++)
        std::cin >> arr[i];
    
    std::sort(arr, arr + len);

    int prev = arr[0];
    std::cout << prev;

    for (int i = 1; i < len; i++)
    {
        if (arr[i] == prev)
            continue;
        
        std::cout << ' ' << arr[i];
        prev = arr[i];
    }
}