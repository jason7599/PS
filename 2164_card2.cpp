#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n_cards;
    std::cin >> n_cards;

    std::queue<int> deck;
    for (int i = 1; i <= n_cards; i++)
        deck.push(i);
    
    while (deck.size() > 1)
    {
        deck.pop();
        deck.push(deck.front());
        deck.pop();
    }

    std::cout << deck.front() << '\n';
}