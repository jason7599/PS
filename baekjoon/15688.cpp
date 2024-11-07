#include <iostream>
#include <algorithm>

int arr_len;
int arr[(int)1e6];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> arr_len;
    for (int i = 0; i < arr_len; i++)
        std::cin >> arr[i];

    std::sort(arr, arr + arr_len);

    for (int i = 0; i < arr_len; i++)
        std::cout << arr[i] << '\n';
}