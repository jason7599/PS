#include <iostream>

int get_val(const char hand[2])
{
    int val = 0;
    int a_cnt = 0;

    for (int i = 0; i < 2; i++)
    {
        switch (hand[i])
        {
        case 'A':
            a_cnt++;
            break;
        case 'K':
        case 'Q':
        case 'J':
            val += 10;
            break;
        case 'T':
            val += 10;
            break;
        default:
            val += hand[i] - '0';
            break;
        }
    }

    while (a_cnt--)
        val += (val + 11 > 21 ? 1 : 11);

    return val;
}

const char cards[] = "A23456789TJQK";

int main()
{
    std::cout.precision(3);
    std::cout << std::fixed;

    while (1)
    {
        int num_decks;
        std::cin >> num_decks;

        if (!num_decks)
            break;
        
        char dealer[2], player[2];
        std::cin >> dealer[0];
        std::cin >> player[0] >> player[1];

        float win_chance = 0;
        for (int i = 0; i < 13; i++)
        {
            char card = dealer[1] = cards[i];

            int card_cnt = 4 * num_decks
                - (dealer[0] == card)
                - (player[0] == card) - (player[1] == card);
            
            int dealer_v = get_val(dealer);
            int player_v = get_val(player);

            bool win = player_v <= 21
                && (dealer_v > 21 || player_v > dealer_v);

            if (win)
                win_chance += (float)card_cnt / (52 * num_decks - 3);
        }

        std::cout << 100 * win_chance << "%\n";
    }
}