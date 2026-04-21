#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> seq(n);
    for (int& x : seq)
        std::cin >> x;
    
    int next = 1;
    std::stack<int> stk;
    std::vector<char> ops;

    for (int x : seq)
    {
        while (x >= next)
        {
            stk.push(next++);
            ops.push_back('+');
        }
                
        if (stk.empty() || stk.top() != x)
        {
            std::cout << "NO\n";
            return 0;
        }
        
        stk.pop();
        ops.push_back('-');
    }

    for (char c : ops)
        std::cout << c << '\n';
}