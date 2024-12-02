#include <iostream>
#include <string>

bool solve(const std::string& src, const std::string& dest, size_t src_i, size_t dest_i, size_t move0, size_t move1, int moved_cnt)
{
    if (dest_i == dest.length())
        return 1;
    
    if (moved_cnt == 2)
        return src.substr(src_i) == dest.substr(dest_i);
    
    
}

int main()
{
    {int t; std::cin >> t;}

    std::string src, dest;
    std::cin >> src >> dest;

    size_t move0, move1;
    std::cin >> move0 >> move1;
}