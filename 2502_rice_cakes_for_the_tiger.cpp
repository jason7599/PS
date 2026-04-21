#include <iostream>

using namespace std;

int fib(int n)
{
    static int dp[30];

    if (n < 3)
        return 1;

    if (dp[n])
        return dp[n];
    
    return dp[n] = fib(n - 1) + fib(n - 2);
}

pair<int, int> solve(int day, int amount)
{
    int f0 = fib(day - 2);
    int f1 = fib(day - 1);

    int first;
    for (first = 1; (amount - f0 * first) % f1; first++);

    return {first, (amount - f0 * first) / f1};
}

int main()
{
    int day, amount;
    cin >> day >> amount;
    auto [first, second] = solve(day, amount);
    cout << first << '\n' << second;
    return 0;
}   