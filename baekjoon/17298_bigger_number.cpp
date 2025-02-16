#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_elems;
    std::cin >> n_elems;

    std::vector<int> elems(n_elems);
    for (int& elem : elems)
        std::cin >> elem;

    std::vector<int> res(n_elems, -1);
    std::stack<int> stk;

    for (int i = 0; i < n_elems; i++)
    {
        int x = elems[i];

        while (!stk.empty() && elems[stk.top()] < x)
        {
            res[stk.top()] = x;
            stk.pop();
        }

        stk.push(i);
    }

    for (int i : res)
        std::cout << i << ' ';
    std::cout << '\n';
}