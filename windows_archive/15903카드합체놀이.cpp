#include <iostream>
#include <queue>

using namespace std;

using ll = long long int;

int main()
{
    int num_cards, num_merges;
    cin >> num_cards >> num_merges;

    priority_queue<ll, vector<ll>, greater<ll>> cards;

    for (int i = 0; i < num_cards; i++)
    {
        int card;
        cin >> card;
        cards.push(card);
    }

    for (int i = 0; i < num_merges; i++)
    {
        ll x = cards.top(); 
        cards.pop();
        ll y = cards.top();
        cards.pop();

        cards.push(x + y);
        cards.push(x + y);
    }

    ll sum = 0;
    while (!cards.empty())
    {
        sum += cards.top();
        cards.pop();
    }

    cout << sum;

    return 0;
}