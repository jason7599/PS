#include <iostream>

int main()
{
    int n_stones;
    std::cin >> n_stones;

    bool puang_turn = 1;
    int n_take = 1;

    int turn = 1;

    while (1)
    {
        if (n_stones < n_take)
        {
            if (puang_turn) 
                std::cout << n_take - n_stones;
            else 
                std::cout << 0;
            break;
        }
        else
            n_stones -= n_take++;

        puang_turn = !puang_turn;
    }
}