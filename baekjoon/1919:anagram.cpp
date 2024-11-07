#include <iostream>
#include <array>

using std::array;

int main() try
{
    std::array<int, 5> arr;
    for (int i = 0; i < 5; i++)
        std::cin >> arr.at(i);

    for (int a : arr)
        std::cout << a << ' ';
    std::cout << std::endl;
} 
catch (std::exception e) 
{
    std::cout << "Exception caught: " << e.what() << std::endl;
}
