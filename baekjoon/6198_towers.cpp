#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_towers;
    std::cin >> n_towers;

    std::stack<int> stk;
    int sum = 0;

    while (n_towers--)
    {
        int height;
        std::cin >> height;

        while (!stk.empty() && stk.top() <= height)
            stk.pop();
        
        sum += stk.size();

        stk.push(height);
    }   

    std::cout << sum;
}