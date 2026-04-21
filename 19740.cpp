#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int main()
{
    int num_files;
    std::cin >> num_files;

    std::string name;
    std::cin >> name;

    int max_file_num = std::pow(10, name.length()) - 1;
    int min_file_num = std::max(std::stoi(name), (int)std::pow(10, name.length() - 1));

    for (int i = 1; i < num_files; i++)
    {
        std::cin >> name;
        min_file_num = std::max(min_file_num, std::stoi(name));
    }

    std::cout << min_file_num << '\n';
    std::cout << max_file_num;
}