#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int arr[1000];

    int t;
    std::cin >> t;
    std::cout << t << "\n\n";
    while (t--)
    {
        int len;
        std::cin >> len;
        std::cout << len << '\n';
        for (int i = 0; i < len; i++)
            std::cin >> arr[i];
        
        std::sort(arr, arr + len);

        int temp = arr[len - 1];
        arr[len - 1] = arr[len - 2];
        arr[len - 2] = temp;

        for (int i = 0; i < len; i++)
            std::cout << arr[i] << ' ';
        if (t)
            std::cout << "\n\n";
    }
}