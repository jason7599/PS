#include <iostream>

// return if the starting player can win given num_stones stones
// bool solve(long long num_stones)
// {
//     if (num_stones == 1 || num_stones == 3)
//         return 1;
    
//     return !solve(num_stones - 1) || !solve(num_stones - 3);
// }

bool can_win(long long num_stones)
{
    return num_stones % 2;
}

int main()
{
    long long num_stones;
    std::cin >> num_stones;
    std::cout << (can_win(num_stones) ? "SK" : "CY");
}