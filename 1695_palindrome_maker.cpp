#include <iostream>
#include <algorithm>

int arr[5'000];

int solve(int l, int r)
{
    static int memo[5000][5000];

    if (r <= l)
        return 0;

    if (memo[l][r])
        return std::max(memo[l][r], 0);

    if (arr[l] == arr[r])
        return solve(l + 1, r - 1);
    
    int res = 1 + std::min(
        solve(l + 1, r), // add arr[l] after r
        solve(l, r - 1) // add arr[r] before l
    );

    memo[l][r] = res ? res : -1;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int arr_len;
    std::cin >> arr_len;

    for (int i = 0; i < arr_len; i++)
        std::cin >> arr[i];
    
    std::cout << solve(0, arr_len - 1);
}