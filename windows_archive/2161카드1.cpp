#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n_cards, card;
    queue<int> card_queue;
    vector<int> card_sequence;

    cin >> n_cards;
    for (int i = 1; i <= n_cards; i++)
        card_queue.push(i);
    
    while (!card_queue.empty())
    {
        card = card_queue.front();
        card_queue.pop();

        card_sequence.push_back(card);

        card = card_queue.front();
        card_queue.pop();
        if (card_queue.empty())
            card_sequence.push_back(card);
        else
            card_queue.push(card);
    }

    for (int card : card_sequence)
        cout << card << ' ';
}