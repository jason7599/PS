#include <iostream>

int n_stones;
int stone_colors[100];

int main()
{
    while (1)
    {
        int n_colors;
        std::cin >> n_stones >> n_colors;

        for (int i = 0; i < n_stones; i++)
            std::cin >> stone_colors[i];
    }
}