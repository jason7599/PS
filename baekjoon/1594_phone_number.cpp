#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

int eval(const std::string& number, int pos, int len)
{
    std::set<char> set;

    for (int i = 0; i < len; i++, pos++)
        set.insert(number[pos]);
    
    if (set.size() == 1)
        return 2;
    
    if (len == 3 && set.size() == 2)
        return 1;
    
    return 0;
}

int dp_len[1000];
int dp_score[1000];

// int solve(const std::string& number, )

int main()
{
    std::string number;
    std::cin >> number;

}
