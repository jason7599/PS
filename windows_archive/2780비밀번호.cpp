#include <iostream>
#include <vector>

using namespace std;

const int mod = 1'234'567;

int dp[10][1'001];
vector<int> neighbors[10] =
{
    {7}, // 0
    {2, 4}, // 1
    {1, 3, 5}, // 2
    {2, 6}, // 3
    {1, 5, 7}, // 4
    {2, 4, 6, 8}, // 5
    {3, 5, 9}, // 6
    {0, 4, 8}, // 7
    {5, 7, 9}, // 8
    {6, 8} // 9
};

int func(int x, int n) // x키로 시작하는 길이 n짜리 개수
{
    if (n == 1)
        return 1;
    
    if (dp[x][n])
        return dp[x][n];
    
    int res = 0;

    for (int neighbor : neighbors[x])
        res += func(neighbor, n - 1);
    
    return dp[x][n] = res % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 10; i++)
            ans += func(i, n);
        cout << ans % mod << '\n';
    }
    return 0;
}