#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s = "hello world";
    std::cout << s.length() << '\n';
    size_t t = s.find_last_not_of(' ');
    std::cout << t << '\n';
    // s.rfind()
    // s.find_first_of
    std::vector<int> v({1, 2, 3});
    v.insert(v.begin(), 0);
    std::cout << v.front() << '\n';
    
}
