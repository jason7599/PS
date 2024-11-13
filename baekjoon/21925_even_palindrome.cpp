#include <iostream>

int arr_len;
int arr[5000];

int main()
{
    std::cin >> arr_len;
    for (int i = 0; i < arr_len; i++)
        std::cin >> arr[i];
    
    int ans = 0;
    int i = 0;
    while (i < arr_len)
    {
        int j;
        for (j = i + 1; j < arr_len; j += 2)
        {
            bool palindrome = 1;
            for (int k = 0; k <= (j - i) / 2; k++)
            {
                if (arr[i + k] != arr[j - k])
                {
                    palindrome = 0;
                    break;
                }
            }
            if (palindrome)
            {
                ans++;
                i = j + 1;
                break;
            }
        }
        if (j >= arr_len)
        {
            ans = -1;
            break;
        }
    }

    std::cout << ans;
}