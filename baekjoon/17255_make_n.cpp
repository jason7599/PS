#include <iostream>
#include <string>
#include <map>

int solve(const std::string& n)
{
    static std::map<std::string, int> memo;

    if (n.length() == 1)
        return 1;

    if (memo.find(n) != memo.end())
        return memo[n];
    
    std::string pop_front = n.substr(1);
    std::string pop_back = n.substr(0, n.length() - 1);

    int res = solve(pop_front);
    if (pop_front != pop_back)
        res += solve(pop_back);

    return memo[n] = res;
}

int main()
{
    std::string n;
    std::cin >> n;
    std::cout << solve(n);
}