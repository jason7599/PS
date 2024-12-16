#include <iostream>
#include <string>

int main()
{
    std::string num;
    std::cin >> num;
    std::cout << (int)(num.find('7') != std::string::npos) * 2 + (std::stoi(num) % 7 == 0);
}