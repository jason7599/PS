#include <iostream>
#include <queue>

int target_hp;
int64_t damage_sum;
std::priority_queue<int, std::vector<int>, std::greater<int>> cards_weakest;

void push_card(int damage)
{
    damage_sum += damage;
    cards_weakest.push(damage);
}

int get_n_min_cards()
{
    if (damage_sum < target_hp)
        return -1;

    while (damage_sum - cards_weakest.top() >= target_hp)
    {
        damage_sum -= cards_weakest.top();
        cards_weakest.pop();
    }

    return cards_weakest.size();
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> target_hp;

    int n_init_cards, n_addit_cards;
    std::cin >> n_init_cards >> n_addit_cards;

    while (n_init_cards--)
    {
        int damage;
        std::cin >> damage;
        push_card(damage);
    }

    std::cout << get_n_min_cards() << '\n';

    while (n_addit_cards--)
    {
        int damage;
        std::cin >> damage;
        push_card(damage);
        std::cout << get_n_min_cards() << '\n';
    }
}