#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string ans;

bool solve(const std::string& num, const std::vector<char>& pool, std::string res = "")
{
    

    return 0;
}

int main()
{
    std::string num;
    int pool_size;
    
    std::cin >> num >> pool_size;
    
    std::vector<char> pool(pool_size);
    for (int i = 0; i < pool_size; i++)
        std::cin >> pool[i];

    std::sort(pool.begin(), pool.end());

    solve(num, pool);

    std::cout << ans;
}