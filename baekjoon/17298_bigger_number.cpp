#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int arr_len;
    std::cin >> arr_len;

    std::vector<int> arr(arr_len);
    for (int& i : arr)
        std::cin >> i;

    std::vector<int> res(arr_len);

    std::stack<int> stack;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stack.empty() && stack.top() <= arr[i])
            stack.pop();
        
        res[i] = stack.empty() ? -1 : stack.top();

        stack.push(arr[i]);
    }

    for (int i : res)
        std::cout << i << ' ';
    std::cout << '\n';
}