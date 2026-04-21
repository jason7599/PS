#include <iostream>
#include <string>
#include <set>

std::string get_next(const std::string& str)
{
    int cnt[10] = {0};

    for (char c : str)
        cnt[c - '0']++;

    std::string res;
    for (int i = 0; i < 10; i++)
    {
        if (cnt[i])
            res += std::to_string(cnt[i]) + (char)(i + '0');
    }
    
    return res;
}

int find(const std::string& start, const std::string& target)
{
    std::set<std::string> set;

    int i = 1;
    std::string str = start;

    while (1)
    {
        if (str == target)
            return i;
    
        set.insert(str);

        std::string next = get_next(str);
        if (set.find(next) != set.end())
            return -1;
        
        str = next;
        i++;
    }
}

int main()
{
    std::string start, target;
    std::cin >> start >> target;

    int res = find(start, target);

    if (res == -1)
        std::cout << "Does not appear";
    else
        std::cout << res;
}