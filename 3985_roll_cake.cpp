#include <iostream>

bool cake_claimed[1001];

int main()
{
    int cake_len, num_people;
    std::cin >> cake_len >> num_people;

    int max_taken = 0;
    int max_taker;

    int max_claim = 0;
    int max_claimant;

    for (int i = 1; i <= num_people; i++)
    {
        int start, end;
        std::cin >> start >> end;

        if (end - start + 1 > max_claim)
        {
            max_claim = end - start + 1;
            max_claimant = i;
        }

        int taken = 0;
        for (int j = start; j <= end; j++)
        {
            if (!cake_claimed[j])
            {
                cake_claimed[j] = 1;
                taken++;
            }
        }

        if (taken > max_taken)
        {
            max_taken = taken;
            max_taker = i;
        }
    }

    std::cout << max_claimant << '\n';
    std::cout << max_taker << '\n';
}