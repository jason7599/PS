#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int len;
bool is_lower[3'000];

int solve(int index, bool lower)
{
    static int dp[3'000][2]; // [index][bool]; bool = is_lower

    if (index == len)
        return 0;
    
    if (dp[index][lower])
        return dp[index][lower];

    if (is_lower[index] == lower)
        return 1 + solve(index + 1, lower);
    
    return dp[index][lower] = 2 + min(
        solve(index + 1, lower), // 입력하고 별 버튼으로 바꾸기
        solve(index + 1, !lower) // 마름모 누르고 입력
    );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    len = input.length();
    for (int i = 0; i < len; i++)
        is_lower[i] = ('a' <= input[i] && input[i] <= 'z');
    
    cout << solve(0, true);

    return 0;
}